
#include "DominoToken.h"

#include <string>

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
    if((this->GetFirstValue() == dominoToken.GetSecondValue()) && (this->GetSecondValue() == dominoToken.GetFirstValue())){
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


std::string DominoToken::GetPrintableToken(){
    std::string PrintableToken;
    PrintableToken = "|" + std::to_string(this->GetFirstValue()) + "|" + std::to_string(this->GetSecondValue()) + "|";
    return PrintableToken;
}

std::string DominoToken::GetReversePrintableToken(){
    std::string PrintableToken;
    PrintableToken = "|" + std::to_string(this->GetSecondValue()) + "|" + std::to_string(this->GetFirstValue()) + "|";
    return PrintableToken;
}