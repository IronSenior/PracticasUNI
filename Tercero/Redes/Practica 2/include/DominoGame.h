

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

    public:
        DominoGame(){
            // I will use -1 for expressing that there is no winner and -2 for a draw
            mWinnerIndex = -1;

        }
        


};

#endif