
#include "HubServer.h"

#include <iostream>
#include <csignal>

void handleSigint(int sig);

HubServer Server(8888, 2);
int main(int argc, char const *argv[]){
    signal(SIGINT, handleSigint);
    Server.StartMatchMacking();
}

void handleSigint(int sig)
{
    Server.CloseServer();
    exit(1);
}