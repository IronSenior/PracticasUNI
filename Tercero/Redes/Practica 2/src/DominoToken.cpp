
#include "DominoToken.h"


void DominoToken::SetValue(int value) {
    if ((value > 6) || (value < 0)){
        throw "Invalid token value";
    }
    this->mValues.push_back(value);
}


bool DominoToken::operator==(DominoToken const & dominoToken) const {
    if((this->GetFirstValue() == dominoToken.GetFirstValue()) && (this->GetSecondValue() == dominoToken.GetSecondValue())){
        return true;
    }
    return false;
}

bool DominoToken::operator>(DominoToken const & dominoToken) const {
    if((this->GetFirstValue() + this->GetSecondValue()) > (dominoToken.GetFirstValue() + dominoToken.GetSecondValue())){
        return true;
    }
    return false;
}

bool DominoToken::operator<(DominoToken const & dominoToken) const {
    if((this->GetFirstValue() + this->GetSecondValue()) < (dominoToken.GetFirstValue() + dominoToken.GetSecondValue())){
        return true;
    }
    return false;
}