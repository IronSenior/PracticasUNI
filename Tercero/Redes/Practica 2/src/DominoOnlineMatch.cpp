#include "DominoOnlineMatch.h"

#include <sys/socket.h>



void DominoOnlineMatch::StartMatch(){
    for (auto PlayerSocketDescriptor = this->mPlayers.begin(); PlayerSocketDescriptor != this->mPlayers.end(); PlayerSocketDescriptor++){
        send(*PlayerSocketDescriptor, "+Ok. Empieza la partida", 100, 0);
    }

    
}