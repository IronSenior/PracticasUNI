
#include "HubServer.h"

#include <iostream>
#include <csignal>

void handleSigint(int sig);


HubServer Server(8888, 2);
int main(int argc, char const *argv[]){
    signal(SIGINT, handleSigint);
    Server.StartServer();
}

void handleSigint(int sig)
{
    std::cout<<"Closing Server"<<std::endl;
    Server.CloseServer();
    exit(1);
}