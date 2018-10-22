#include "jugador.h"
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <iostream>

using std::string;
using std::list;
using std::getline;

bool Jugador::setApuestas(list<apuesta> new_apuesta){
    string file_name;
    char linea[20];
    file_name = getDNI() + ".txt";

    std::ifstream apuesta_file(file_name);

    while(!apuesta_file.eof()){
        apuesta_file.getline(linea, 20);
        std::cout<<linea<<std::endl;
        
    }

}