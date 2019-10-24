


#include "Client.h"
#include <string>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <iostream>
#include <strings.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>

Client::Client(const char* serverIpAddress, int serverPort){
    this->mSocketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    
    if (this->mSocketDescriptor == -1) {
        throw "Client Socket can not be created";
    }

    mSocketName.sin_family = AF_INET;
    mSocketName.sin_port = htons(serverPort);
    mSocketName.sin_addr.s_addr = inet_addr(serverIpAddress);

    if (connect(this->mSocketDescriptor, (struct sockaddr*)&this->mSocketName, sizeof(this->mSocketName)) == -1) {
        throw "Error with CONNECT operation in Client Socket";
    }


}


void Client::RecreateFDSet(){
    FD_ZERO(&this->mReadFds);
    
    FD_SET(0, &this->mReadFds);
    FD_SET(this->mSocketDescriptor, &this->mReadFds);
}


void Client::StartTalking(){
    char buffer[100];
    int fin = 0;

	do{
        this->RecreateFDSet();

        select(this->mSocketDescriptor+1, &this->mReadFds, NULL, NULL, NULL);
        
        //Tengo mensaje desde el servidor
        if(FD_ISSET(this->mSocketDescriptor, &this->mReadFds)){
            bzero(buffer, sizeof(buffer));
            recv(this->mSocketDescriptor, buffer, sizeof(buffer), 0);
            
            printf("%s\n",buffer);
            
        }
        else
        {   
            //He introducido información por teclado
            if(FD_ISSET(0, &this->mReadFds)){
                bzero(buffer, sizeof(buffer));
                
                std::cin>>buffer;
                if(strcmp(buffer,"SALIR\n") == 0){
                    fin = 1;
                }
                send(this->mSocketDescriptor, buffer, sizeof(buffer), 0);
            }
        }
        
        
				
    }while(fin == 0);

    close(this->mSocketDescriptor);

}