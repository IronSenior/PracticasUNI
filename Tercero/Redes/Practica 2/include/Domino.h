//Domino.h


#ifndef DOMINO_H
#define DOMINO_H

#include <DominoToken.h>
#include <vector>

class Domino{
    private:
        std::vector<DominoToken> mFreeTokens;

    public:
        Domino();

        DominoToken GetRandomFreeDominoToken();

        inline int GetNumberOfFreeTokens() const {
            return mFreeTokens.size();
        };
};

#endif