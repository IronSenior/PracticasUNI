

#ifndef DOMINOPLAYER_H
#define DOMINOPLAYER_H

#include "DominoToken.h"
#include <vector>

class DominoPlayer{
    private:
        std::vector<DominoToken> mDominoHand;

    public:

        DominoPlayer();

        void RecieveToken(DominoToken token);

        inline int GetNumberOfTokens() const {
            return this->mDominoHand.size();
        }
};


#endif