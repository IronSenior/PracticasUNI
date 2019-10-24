
#ifndef HUBSERVER_H
#define HUBSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <vector>

class HubServer {
    private:
        int mSocketDescriptor;
        int mCapacity;
        struct sockaddr_in mSocketName;
        std::vector<int> mClients;

        fd_set mReadSet;

    public:
        HubServer(int port, int serverCapacity);

        inline void CloseServer(){
            close(this->mSocketDescriptor);
        }

        void AddNewClient();

        void CreateMatchThread(std::vector<int> clients);

        void RecreateFDSet();

        void StartMatchMacking();

        void HandleMessage(int clientSocketDescriptor, const char* message);
};

#endif