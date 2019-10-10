
#include "DominoToken.h"


void DominoToken::SetValue(int value) {
    if ((value > 6) || (value < 0)){
        throw "Invalid token value";
    }
    this->mValues.push_back(value);
}
