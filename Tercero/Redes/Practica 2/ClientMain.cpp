
#include "Client.h"
#include <iostream>
#include <csignal>

void handleSigint(int sig);

Client DoClient("127.0.0.1", 2050);
int main(int argc, char const *argv[])
{
    signal(SIGINT, handleSigint);
    DoClient.StartTalking();
    return 0;
}


void handleSigint(int sig)
{
    DoClient.CloseClient();
    exit(1);
}