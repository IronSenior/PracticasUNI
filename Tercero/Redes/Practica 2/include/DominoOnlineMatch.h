#ifndef DOMINOONLINEMATCH_H
#define DOMINOONLINEMATCH_H

#include<vector>


class DominoOnlineMatch{
    private:
        std::vector<int> mPlayers;


    public:
        DominoOnlineMatch(std::vector<int> matchPlayer){
            this->mPlayers = matchPlayer;
        };

        void StartMatch();
};

#endif