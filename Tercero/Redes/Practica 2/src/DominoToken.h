//DominoToken.h
#ifndef DOMINOTOKEN_H
#define DOMINOTOKEN_H


#include <vector>

class DominoToken{
    private:
        std::vector<int> mValues;
        bool mIsDouble;

    public:
        DominoToken(int firstValue, int secondValue){
            this->mValues[0] = firstValue;
            this->mValues[1] = secondValue;

            if (firstValue == secondValue){
                this->mIsDouble = true;
            }
            else{
                this->mIsDouble = false;
            }
            return this;
        };

        inline int GetFirstValue() const {
            return mValues[0];
        };

        inline int GetSecondValue() const {
            return mValues[1];
        };

        inline std::vector<int> GetValues() const {
            return mValues;
        };

        int IsDouble() const {
            return mIsDouble;
        };
};

#endif