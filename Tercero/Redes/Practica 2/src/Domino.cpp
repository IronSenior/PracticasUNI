
#include "Domino.h"
#include "DominoToken.h"


#include <cstdlib>
#include <ctime>

DominoToken::DominoToken Domino::GetRandomFreeDominoToken(){
    /* initialize random seed: */
    srand(time(NULL));
    
    int random_token = rand() % 28 ; //TODO 

}
