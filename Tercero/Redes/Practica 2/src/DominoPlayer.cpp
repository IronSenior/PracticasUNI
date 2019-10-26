#include "DominoPlayer.h"
#include "DominoToken.h"




DominoToken DominoPlayer::GetFirstToken() {
    this->SortHand();
    for(auto Token = this->mDominoHand.begin(); Token != this->mDominoHand.end(); Token++){
        if (Token->IsDouble()){
            return *Token;
        }
    }
    return this->mDominoHand[0];

}

void DominoPlayer::SortHand(){
    // Bubble sort (Max, Min)
    DominoToken TempToken(0,0);
    for(int i= 1; i < this->GetNumberOfTokens(); i++){
        for(int j= 0; j < (this->GetNumberOfTokens() -1); j++){
            if(this->mDominoHand[j] < this->mDominoHand[j+1]){
                TempToken = this->mDominoHand[j];
                this->mDominoHand[j] = this->mDominoHand[j+1];
                this->mDominoHand[j+1] = TempToken;

            }
        }
    }
    
}

void DominoPlayer::QuitToken(DominoToken &dominoToken){
    for (int i=0; i < this->GetNumberOfTokens(); i++){
        if (this->mDominoHand[i] == dominoToken){
            this->mDominoHand.erase(this->mDominoHand.begin() + i);
            return;
        }
    }
}