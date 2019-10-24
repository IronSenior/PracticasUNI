

#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <vector>

class Client{
    private:
        int mSocketDescriptor;
        struct sockaddr_in mSocketName;

        fd_set mReadFds; 
        fd_set mAuxFds;
    public:
        Client(const char* serverIpAddress, int serverPort);

        void StartTalking();

        void RecreateFDSet();

        inline void CloseClient(){
            close(this->mSocketDescriptor);
        };
};


#endif