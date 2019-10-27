
#include "HubServer.h"
#include "DominoOnlineMatch.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <future>
#include <regex>
#include <fstream>


#define BUFFER_SIZE 250

std::vector<int> HubServer::mHubClients;


HubServer::HubServer(int port, int serverCapacity){

    this->mCapacity = serverCapacity;
    this->mSocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    
    if (this->mSocketDescriptor == -1) {
        throw std::runtime_error("Server Socket can not be created");
    }

    mSocketName.sin_family = AF_INET;
    mSocketName.sin_port = htons(port);
    mSocketName.sin_addr.s_addr = INADDR_ANY;

    if (bind(this->mSocketDescriptor, (struct sockaddr*)&this->mSocketName, sizeof(this->mSocketName)) == -1) {
        throw std::runtime_error("Error with BIND operation in Server Socket");
    }

    if (listen(this->mSocketDescriptor, this->mCapacity) == -1) {
        throw std::runtime_error("Error with LISTEN operation in Server Socket");
    }
}


void HubServer::CloseServer(){
    for (auto clientSocketDescriptor = mHubClients.begin(); clientSocketDescriptor != mHubClients.end(); ++clientSocketDescriptor){
        close(*clientSocketDescriptor);
    }
    close(this->mSocketDescriptor);
}


void HubServer::AcceptNewConnection(){
    int NewClientSocketDescriptor;
    struct sockaddr_in NewClientSocketName;
    socklen_t NewClientSocketNameLen;
    char buffer[BUFFER_SIZE];

    if ((NewClientSocketDescriptor = accept(this->mSocketDescriptor, (struct sockaddr*)&NewClientSocketName, &NewClientSocketNameLen)) == -1) {
        throw std::runtime_error("Error adding new client to server");
    }

    mHubClients.push_back(NewClientSocketDescriptor);

    sprintf(buffer, "Bienvenido al Domino");
    send(NewClientSocketDescriptor, buffer, BUFFER_SIZE, 0);

    std::cout<< "New client with id "<<NewClientSocketDescriptor<< " has connected\n";
}


void HubServer::RecreateFDSet(){
    FD_ZERO(&this->mReadSet);
    FD_SET(this->mSocketDescriptor, &this->mReadSet);

    for (auto clientSocketDescriptor = mHubClients.begin(); clientSocketDescriptor != mHubClients.end(); ++clientSocketDescriptor) {
        FD_SET(*clientSocketDescriptor, &this->mReadSet);

    }
}


void HubServer::StartServer(){
    char buffer[BUFFER_SIZE];

    while (1) {
        this->RecreateFDSet();

        struct timespec time;
        time.tv_sec=10;
        
    
        pselect(FD_SETSIZE, &this->mReadSet, NULL, NULL, &time, NULL);
        
        for (auto clientSocketDescriptor = mHubClients.begin(); clientSocketDescriptor != mHubClients.end(); ++clientSocketDescriptor) {
            if (FD_ISSET(*clientSocketDescriptor, &this->mReadSet)) {
                if ((recv(*clientSocketDescriptor, &buffer, BUFFER_SIZE, 0) > 0)){
                    this->HandleMessage(*clientSocketDescriptor, buffer);
                    break;
                }
            }
        }

        if (FD_ISSET(this->mSocketDescriptor, &this->mReadSet)) {
            this->AcceptNewConnection();
        }
    }
}


void HubServer::HandleMessage(int clientSocketDescriptor, const char* message){
    std::cmatch RegexMatches;
    std::cout<<"From "<<clientSocketDescriptor<<" Recieved: "<<message<<std::endl;

    if (strcmp(message, "INICIAR-PARTIDA") == 0){
        if(this->IsClientLogged(clientSocketDescriptor)){
            this->StartMatchMacking(clientSocketDescriptor);
        }
        else{
            send(clientSocketDescriptor, "-ERR. Te tienes que Loggear Primero", BUFFER_SIZE, 0);
        }
    }
    else if(std::regex_search(message, RegexMatches, std::regex("USUARIO (.*)"))){
        if(! this->IsClientLogged(clientSocketDescriptor)){
            this->mThreads.push_back(std::async(std::launch::async, [this, clientSocketDescriptor, RegexMatches]{
                return this->LogInClient(clientSocketDescriptor, RegexMatches.str(1));
            }));
        }
        else{
            send(clientSocketDescriptor, "-ERR. Ya estas Logueado", BUFFER_SIZE, 0);
        }
    }
    else if(std::regex_search(message, RegexMatches, std::regex("REGISTRO -u (.*) -p (.*)"))){
        if(! this->IsClientLogged(clientSocketDescriptor)){
            this->RegisterUser(RegexMatches.str(1), RegexMatches.str(2));
        }
        else{
            send(clientSocketDescriptor, "-ERR. Ya estas Logueado", BUFFER_SIZE, 0);
        }
    }  
    else
    {
        send(clientSocketDescriptor, "-ERR. Bad Message", BUFFER_SIZE, 0);
    }
}


void HubServer::StartMatchMacking(int clientSocketDescriptor){

    std::vector<int> MatchPlayers;
    MatchPlayers.push_back(clientSocketDescriptor); 

    if (this->mPlayersQueue.size() > 0){
        MatchPlayers.push_back(mPlayersQueue[0]);
        this->mPlayersQueue.erase(this->mPlayersQueue.begin() + 0);

        // For now on the clients would be managed by DominoOnlineMatchClass
        this->EraseClients(MatchPlayers);

        // I save the matches in a vector only to ensure them for the threads
        this->mMatches.push_back(*new DominoOnlineMatch(this->mSocketDescriptor, MatchPlayers));
        this->mThreads.push_back(std::async(std::launch::async, [this]{return this->mMatches.back().StartMatch();}));
    }
    else{
        this->mPlayersQueue.push_back(clientSocketDescriptor);
        send(clientSocketDescriptor, "+Ok. Petición Recibida. Quedamos a la espera de más jugadores", BUFFER_SIZE, 0);
    }
}


void HubServer::EraseClients(std::vector<int> clientsToErase){
    for (unsigned int i = 0; i < clientsToErase.size(); i++){
        for (unsigned int j = 0; j < mHubClients.size(); j++){
            if (clientsToErase[i] == mHubClients[j]){
                mHubClients.erase(mHubClients.begin() + j);
            }
        }
    }
}

void HubServer::AddClients(std::vector<int> clientsToAdd){
    for (auto ClientToAdd = clientsToAdd.begin(); ClientToAdd != clientsToAdd.end(); ClientToAdd++){
        mHubClients.push_back(*ClientToAdd);
    }
    this->RecreateFDSet();
}


bool HubServer::IsClientLogged(int clientSocketDescriptor){
    for(auto LoggedClient: this->mLoggedClients){
        if(LoggedClient == clientSocketDescriptor){
            return true;
        }
    }
    return false;
}


// This should be an independent class with all user staff but i dont have time
int HubServer::LogInClient(int clientSocketDescriptor, std::string userName){
    fd_set AuxSet;
    char buffer[BUFFER_SIZE];
    std::cmatch RegexMatches;

    std::vector<int> ClientInVector = {clientSocketDescriptor};
    this->EraseClients(ClientInVector);

    FD_ZERO(&AuxSet);
    FD_SET(this->mSocketDescriptor, &AuxSet);
    FD_SET(clientSocketDescriptor, &AuxSet);

    pselect(FD_SETSIZE, &AuxSet, NULL, NULL, NULL, NULL);
    if (FD_ISSET(clientSocketDescriptor, &AuxSet)) {
        if ((recv(clientSocketDescriptor, &buffer, BUFFER_SIZE, 0) > 0)){
            if(std::regex_search(buffer, RegexMatches, std::regex("PASSWORD (.*)"))){
                if(this->CheckUser(userName, RegexMatches[1])){
                    this->mLoggedClients.push_back(clientSocketDescriptor);
                    this->AddClients(ClientInVector);
                }
                else{
                    send(clientSocketDescriptor, "Err, Usuario o Contraseña no validos", BUFFER_SIZE, 0);
                    this->AddClients(ClientInVector);
                }
            }
            else{
                send(clientSocketDescriptor, "Err. Esperaba contraseña", BUFFER_SIZE, 0);
                this->AddClients(ClientInVector);
            }
        }
    }
    return 0;
}


bool HubServer::CheckUser(std::string userName, std::string password){
    std::ifstream UsersFile("usuarios.txt");

    char User[BUFFER_SIZE];

    while(!UsersFile.eof()) {
        UsersFile >> User;
        if(strcmp(User,(userName + ";" + password).c_str())== 0){
            return true;
        }
    }
    UsersFile.close();
    return false;
}


void HubServer::RegisterUser(std::string userName, std::string password){
    std::ofstream UsersFile("usuarios.txt"); 

    UsersFile<<userName<<";"<<password<<std::endl;

    UsersFile.close();
}