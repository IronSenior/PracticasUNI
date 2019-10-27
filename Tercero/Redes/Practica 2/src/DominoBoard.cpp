
#include "DominoBoard.h"
#include "DominoToken.h"

bool DominoBoard::PutTokenOnRight(DominoToken& token){
    if(this->CanPutOnRight(token)){
        this->mTokens.push_back(token);
        if (token.GetFirstValue() == this->mNumberOnRight){
            this->mPrintableBoard += token.GetPrintableToken();
            this->mNumberOnRight = token.GetSecondValue();
        }
        else{
            this->mPrintableBoard += token.GetReversePrintableToken();
            this->mNumberOnRight = token.GetFirstValue();
        }
        return true;
    }
    return false;
}


bool DominoBoard::CanPutOnRight(DominoToken& token) const{
    for(int i=0; i<2; i++){
        if (this->mNumberOnRight == token.GetValues()[i]){
            return true;
        }
    }
    return false;
}


bool DominoBoard::PutTokenOnLeft(DominoToken& token){
    if(this->CanPutOnLeft(token)){
        this->mTokens.push_back(token);
        if (token.GetFirstValue() == this->mNumberOnLeft){
            this->mPrintableBoard = token.GetReversePrintableToken() + this->mPrintableBoard;
            this->mNumberOnLeft = token.GetSecondValue();
        }
        else{
            this->mPrintableBoard = token.GetPrintableToken() + this->mPrintableBoard;
            this->mNumberOnLeft = token.GetFirstValue();
        }
        return true;
    }
    return false;
}


bool DominoBoard::CanPutOnLeft(DominoToken& token) const{
    for(int i=0; i<2; i++){
        if (this->mNumberOnLeft == token.GetValues()[i]){
            return true;
        }
    }
    return false;
}

void DominoBoard::PutFirstToken(DominoToken& token){
    if((this->mNumberOnLeft == -1) && (this->mNumberOnRight == -1)){
        this->mPrintableBoard = token.GetPrintableToken();
        this->mNumberOnLeft = token.GetFirstValue();
        this->mNumberOnRight = token.GetSecondValue();
    }
    else{
        throw "First token is already put";
    }

}


bool DominoBoard::CanPlayerPutToken(DominoPlayer player){
    for (auto token: player.GetHand()){
        if ((this->CanPutOnLeft(token)) || (this->CanPutOnRight(token))){
            return true;
        }
    }
    return false;
}