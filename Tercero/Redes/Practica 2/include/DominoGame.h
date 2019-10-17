

#ifndef DOMINOGAME_H
#define DOMINOGAME_H

#include "Domino.h"
#include "DominoToken.h"
#include "DominoPlayer.h"
#include "DominoBoard.h"

#include <vector>


class DominoGame{
    private:
        std::vector<DominoPlayer> mPlayers;
        int mWinnerIndex;
        int mTurnIndex;

    public:
        DominoGame(std::vector<DominoPlayer> players){
            // I will use -1 for expressing that there is no winner and -2 for a draw
            this->mWinnerIndex = -1;
            this->mPlayers = players;
            int mTurnIndex = 0;
        } 
};

#endif