#include "jugador.h"
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>

using std::string;
using std::list;

bool Jugador::setApuestas(list<apuesta> new_apuesta){
    std::ofstream apuesta_file;
    string file_name;
    file_name = getDNI() + ".txt";
    apuesta_file.open(file_name);
    apuesta_file.close();
    
}