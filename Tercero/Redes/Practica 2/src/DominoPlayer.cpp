#include "DominoPlayer.h"
#include "DominoToken.h"



DominoToken DominoPlayer::GetBiggestToken() {

    DominoToken BiggestToken(0,0);
    for(int i=0; i< this->GetNumberOfTokens(); i++){
        if(this->mDominoHand[i] > BiggestToken ){
            BiggestToken = this->mDominoHand[i];
        }
    }

    return BiggestToken;
}


void DominoPlayer::QuitToken(DominoToken &dominoToken){
    for (int i=0; i < this->GetNumberOfTokens(); i++){
        if (this->mDominoHand[i] == dominoToken){
            this->mDominoHand.erase(this->mDominoHand.begin() + i);
            return;
        }
    }
}