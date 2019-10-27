

#ifndef DOMINOPLAYER_H
#define DOMINOPLAYER_H

#include "DominoToken.h"
#include <vector>
#include <string>

class DominoPlayer{
    private:
        int mSocketDescriptor;
        std::vector<DominoToken> mDominoHand;

    public:
        DominoPlayer(int playerSocketDescriptor){
            this->mSocketDescriptor = playerSocketDescriptor;
        };

        inline void RecieveToken(DominoToken token) {
            this->mDominoHand.push_back(token);
        };

        inline int GetNumberOfTokens() const {
            return this->mDominoHand.size();
        };

        inline int GetSocketDescriptor() const {
            return this->mSocketDescriptor;
        }

        inline std::vector<DominoToken> GetHand(){
            return this->mDominoHand;
        }

        void SortHand();

        void QuitToken(DominoToken &dominoToken);

        DominoToken GetFirstToken();

        DominoToken GetBiggestDoubleToken();

        DominoToken GetBiggestToken();
        
        std::string GetPrintableHand();

        bool HasToken(DominoToken token);

        
};
#endif