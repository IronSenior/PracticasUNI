
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
        std::vector<int> mPlayersQueue;

        fd_set mReadSet;

    public:
        HubServer(int port, int serverCapacity);

        void StartServer();

        void CloseServer();

        void AddNewClient();

        void RecreateFDSet();

        void StartMatchMacking(int clientSocketDescriptor);

        void CreateMatch(std::vector<int> matchPlayers);

        void HandleMessage(int clientSocketDescriptor, const char* message);
};

#endif