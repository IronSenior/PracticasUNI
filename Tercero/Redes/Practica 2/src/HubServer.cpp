
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
    char buffer[100];

    if ((NewClientSocketDescriptor = accept(this->mSocketDescriptor, (struct sockaddr*)&NewClientSocketName, &NewClientSocketNameLen)) == -1) {
        throw std::runtime_error("Error adding new client to server");
    }

    mHubClients.push_back(NewClientSocketDescriptor);

    sprintf(buffer, "Bienvenido al Domino");
    send(NewClientSocketDescriptor, buffer, 100, 0);

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
    char buffer[100];

    while (1) {
        this->RecreateFDSet();
    
        pselect(FD_SETSIZE, &this->mReadSet, NULL, NULL, NULL, NULL);
        
        for (auto clientSocketDescriptor = mHubClients.begin(); clientSocketDescriptor != mHubClients.end(); ++clientSocketDescriptor) {
            if (FD_ISSET(*clientSocketDescriptor, &this->mReadSet)) {
                if ((recv(*clientSocketDescriptor, &buffer, 100, 0) > 0)){
                    this->HandleMessage(*clientSocketDescriptor, buffer);
                } 
            }
        }

        if (FD_ISSET(this->mSocketDescriptor, &this->mReadSet)) {
            this->AcceptNewConnection();
        }
    }
}


void HubServer::HandleMessage(int clientSocketDescriptor, const char* message){
    char buffer[100];
    std::cout<<"From "<<clientSocketDescriptor<<" Recieved: "<<message<<std::endl;

    if (strcmp(message, "INICIAR-PARTIDA") == 0){
        this->StartMatchMacking(clientSocketDescriptor);
    }
    else
    {
        send(clientSocketDescriptor, "Bad Message", 100, 0);
        std::cout<<"-ERR: Message not kown"<<std::endl;
    }
    

    sprintf(buffer, "Recibido");
    send(clientSocketDescriptor, buffer, 100, 0);
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
        send(clientSocketDescriptor, "+Ok. Petición Recibida. Quedamos a la espera de más jugadores", 100, 0);
    }
}


void HubServer::EraseClients(std::vector<int> clientsToErase){
    for (int i = 0; i < clientsToErase.size(); i++){
        for (int j = 0; j < mHubClients.size(); j++){
            if (clientsToErase[i] == mHubClients[j]){
                mHubClients.erase(mHubClients.begin() + (j - 1));
            }
        }
    }
}

void HubServer::AddClients(std::vector<int> clientsToAdd){
    for (auto ClientToAdd = clientsToAdd.begin(); ClientToAdd != clientsToAdd.end(); ClientToAdd++){
        mHubClients.push_back(*ClientToAdd);
    }
}