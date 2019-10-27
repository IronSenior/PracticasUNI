
#ifndef DOMINOBOARD_H
#define DOMINOBOARD_H


#include "DominoToken.h"
#include "DominoPlayer.h"
#include <vector>
#include <string>

class DominoBoard{
    private:
        std::vector<DominoToken> mTokens;
        std::string mPrintableBoard;
        int mNumberOnLeft;
        int mNumberOnRight;

    public:
        DominoBoard(){
            this->mNumberOnLeft = -1;
            this->mNumberOnRight = -1;
        };

        bool CanPutOnRight(DominoToken& token) const;

        // Returns false if the player can not put the passed token
        // Returns True if the player has put the token successfully
        bool PutTokenOnRight(DominoToken& token);

        bool CanPutOnLeft(DominoToken& token) const;

        // Returns false if the player can not put the passed token
        // Returns True if the player has put the token successfully
        bool PutTokenOnLeft(DominoToken& token);

        void PutFirstToken(DominoToken& token);

        inline std::string GetPrintableBoard() const {
            return this->mPrintableBoard;
        };

        bool CanPlayerPutToken(DominoPlayer player);
};
#endif