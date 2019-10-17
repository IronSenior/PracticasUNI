
#include "Domino.h"
#include "DominoToken.h"


#include <cstdlib>
#include <ctime>

Domino::Domino(){
    for(int i=0; i<7; i++){
        for (int j=i; j<7; j++){
            this->mFreeTokens.push_back(DominoToken(i, j));
        }
    }
}


DominoToken Domino::GetRandomFreeDominoToken(){
    /* initialize random seed: */
    srand(time(NULL));
    
    int RandomTokenIndex = rand() % this->GetNumberOfFreeTokens();
    DominoToken ReturnedToken = this->mFreeTokens[RandomTokenIndex];

    this->mFreeTokens.erase(this->mFreeTokens.begin() + RandomTokenIndex);

    return ReturnedToken;
}
