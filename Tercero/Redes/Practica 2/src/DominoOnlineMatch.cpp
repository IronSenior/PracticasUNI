#include "DominoOnlineMatch.h"

#include <sys/socket.h>
#include <future>
#include <string>
#include <cstring>


int DominoOnlineMatch::StartMatch(){
    this->SendMessageToBothPlayers("Y se termina");
    return 1;
}

void DominoOnlineMatch::SendMessageToBothPlayers(std::string message){
    for (auto PlayerSocketDescriptor = this->mPlayers.begin(); PlayerSocketDescriptor != this->mPlayers.end(); PlayerSocketDescriptor++){
        send(*PlayerSocketDescriptor, message.c_str(), 100, 0);
    }
}
