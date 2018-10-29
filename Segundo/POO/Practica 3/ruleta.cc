#include "ruleta.h"
#include <cstdbool>

Ruleta::Ruleta(Crupier new_crupier){
    crupier_ = new_crupier;
    banca_ = 1000000;
    bola_ = -1;
}

bool Ruleta::setBanca(int new_banca){
    if (new_banca < 0 ){
        return false;
    }
    banca_ = new_banca;
    return true;
}

bool Ruleta::setBola(int new_bola){
    if ((new_bola < 0) || (new_bola > 36)){
        return false;
    }
    bola_ = new_bola;
}