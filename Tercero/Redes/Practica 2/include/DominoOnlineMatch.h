#ifndef DOMINOONLINEMATCH_H
#define DOMINOONLINEMATCH_H

#include <vector>
#include <string>


class DominoOnlineMatch{
    private:
        std::vector<int> mPlayers;

    public:
        DominoOnlineMatch(std::vector<int> matchPlayer){
            this->mPlayers = matchPlayer;

            this->SendMessageToBothPlayers("+Ok. Empieza la partida");
        };

        int StartMatch();

        void SendMessageToBothPlayers(std::string message);

};

#endif