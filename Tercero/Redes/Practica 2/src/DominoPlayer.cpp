#include "DominoPlayer.h"
#include "DominoToken.h"


#include <string>

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


std::string DominoPlayer::GetPrintableHand(){
    std::string PrintableHand;

    for (auto token = this->mDominoHand.begin(); token != this->mDominoHand.end(); token++){
        PrintableHand += token->GetPrintableToken();
    }

    return PrintableHand;
}


bool DominoPlayer::HasToken(DominoToken token){
    for(auto PlayerToken: this->mDominoHand){
        if (PlayerToken == token){
            return true;
        }
    }
    return false;
}