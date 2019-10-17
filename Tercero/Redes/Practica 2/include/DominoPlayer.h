

#ifndef DOMINOPLAYER_H
#define DOMINOPLAYER_H

#include "DominoToken.h"
#include <vector>

class DominoPlayer{
    private:
        std::vector<DominoToken> mDominoHand;

    public:
        DominoPlayer(){};

        inline void RecieveToken(DominoToken token) {
            this->mDominoHand.push_back(token);
        };

        inline int GetNumberOfTokens() const {
            return this->mDominoHand.size();
        };


        void QuitToken(DominoToken &dominoToken);

        DominoToken GetBiggestToken();
};
#endif