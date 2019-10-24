
#include "HubServer.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>

#include <iostream>

HubServer::HubServer(int port, int serverCapacity){

    this->mCapacity = serverCapacity;
    this->mSocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    
    if (this->mSocketDescriptor == -1) {
        throw "Server Socket can not be created";
    }

    mSocketName.sin_family = AF_INET;
    mSocketName.sin_port = htons(port);
    mSocketName.sin_addr.s_addr = INADDR_ANY;

    if (bind(this->mSocketDescriptor, (struct sockaddr*)&this->mSocketName, sizeof(this->mSocketName)) == -1) {
        throw "Error with BIND operation in Server Socket";
    }

    if (listen(this->mSocketDescriptor, this->mCapacity) == -1) {
        throw "Error with LISTEN operation in Server Socket";
    }
}


void HubServer::AddNewClient(){
    int NewClientSocketDescriptor;
    struct sockaddr_in NewClientSocketName;
    socklen_t NewClientSocketNameLen;
    char buffer[100];

    if ((NewClientSocketDescriptor = accept(this->mSocketDescriptor, (struct sockaddr*)&NewClientSocketName, &NewClientSocketNameLen)) == -1) {
        throw "Error adding new client to server";
    }

    this->mClients.push_back(NewClientSocketDescriptor);

    sprintf(buffer, "Bienvenido al Domino");
    send(NewClientSocketDescriptor, buffer, 100, 0);

    std::cout<< "New client with id "<<NewClientSocketDescriptor<< " has connected\n";
}


void HubServer::RecreateFDSet(){
    FD_ZERO(&this->mReadSet);
    FD_SET(this->mSocketDescriptor, &this->mReadSet);


    for (auto clientSocketDescriptor = this->mClients.begin(); clientSocketDescriptor != this->mClients.end(); ++clientSocketDescriptor) {
        FD_SET(*clientSocketDescriptor, &this->mReadSet);

    }
}


void HubServer::StartMatchMacking(){
    char buffer[100];

    while (1) {
        this->RecreateFDSet();
    
        pselect(FD_SETSIZE, &this->mReadSet, NULL, NULL, NULL, NULL);
        
        for (auto clientSocketDescriptor = this->mClients.begin(); clientSocketDescriptor != this->mClients.end(); ++clientSocketDescriptor) {
            if (FD_ISSET(*clientSocketDescriptor, &this->mReadSet)) {
                if ((recv(*clientSocketDescriptor, &buffer, 100, 0) > 0)){
                    this->HandleMessage(*clientSocketDescriptor, buffer);
                } 
            }
        }

        if (FD_ISSET(this->mSocketDescriptor, &this->mReadSet)) {
            this->AddNewClient();
        }
    }
}


void HubServer::HandleMessage(int clientSocketDescriptor, const char* message){
    char buffer[100];
    std::cout<<"From "<<clientSocketDescriptor<<" Recieved: "<<message<<std::endl;
    sprintf(buffer, "Recibido");
    send(clientSocketDescriptor, buffer, 100, 0);
}