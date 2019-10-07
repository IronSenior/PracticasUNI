
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

DominoToken::DominoToken Domino::GetRandomFreeDominoToken(){
    /* initialize random seed: */
    srand(time(NULL));
    
    int random_token = rand() % 28 ; //TODO 

}
