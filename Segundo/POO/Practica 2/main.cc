#include "jugador.h"
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <iostream>

using std::string;
using std::list;
using std::getline;

main(int argc, char const *argv[])
{
    string file_name;
    char linea[20];
    list<apuesta> apuestas;
    //file_name = getDNI() + ".txt";
    file_name = "prueba.txt";

    std::ifstream apuesta_file(file_name);

    while(!apuesta_file.eof()){
        apuesta_file.getline(linea, 20);
        std::cout<<linea<<std::endl;
    
        
    }

    return 0;
}
