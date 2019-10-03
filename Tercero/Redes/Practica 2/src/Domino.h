//Domino.h


#ifndef DOMINO_H
#define DOMINO_H

#include <DominoToken.h>
#include <vector>

class Domino{
    private:
        std::vector<DominoToken::DominoToken> mFreeTokens;

    public:
        Domino() {
            for(int i=0; i<7; i++){
                for (int j=i; j<7){
                    this->mFreeTokens.push_back(new DominoToken(i, j))
                }
            }
        }

        DominoToken::DominoToken GetRandomFreeDominoToken();

        inline int GetNumberOfFreeTokens() const {
            return mFreeTokens.size();
        }
}