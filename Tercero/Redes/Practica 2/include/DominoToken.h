//DominoToken.h
#ifndef DOMINOTOKEN_H
#define DOMINOTOKEN_H


#include <vector>

class DominoToken{
    private:
        std::vector<int> mValues;
        bool mIsDouble;

        void SetValue(int value);

    public:
        DominoToken(int firstValue, int secondValue){
            this->SetValue(firstValue);
            this->SetValue(secondValue);

            if (firstValue == secondValue){
                this->mIsDouble = true;
            }
            else{
                this->mIsDouble = false;
            }
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

        // Operators
        bool operator==(DominoToken const & dominoToken) const; 

        bool operator>(DominoToken const & dominoToken) const;

        bool operator<(DominoToken const & dominoToken) const;
};




#endif