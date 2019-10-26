//DominoToken.h
#ifndef DOMINOTOKEN_H
#define DOMINOTOKEN_H


#include <vector>
#include <string>

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
            return this->mValues[0];
        };

        inline int GetSecondValue() const {
            return this->mValues[1];
        };

        inline std::vector<int> GetValues() const {
            return this->mValues;
        };

        bool IsDouble() const {
            return this->mIsDouble;
        };

        std::string GetPrintableToken();

        std::string GetReversePrintableToken();

        // Operators
        bool operator==(DominoToken const & dominoToken) const; 

        bool operator>(DominoToken const & dominoToken) const;

        bool operator<(DominoToken const & dominoToken) const;
};




#endif