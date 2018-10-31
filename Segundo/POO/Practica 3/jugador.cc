#include "jugador.h"
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <iostream>

using std::string;
using std::list;
using std::getline;
using std::ifstream;

//Asigna las apuestas del jugador que hay en su archivo
void Jugador::setApuestas(){
    string file_name;
    file_name = getDNI() + ".txt";

    apuestas_ = ApuestaFile_(file_name);
}


//Devuelve la lista de apuestas que hay en el archivo de ese jugador
list<Apuesta> Jugador::ApuestaFile_(string file_name){
  list <Apuesta> lapuesta;
  Apuesta apuesta;
  
  string value;
  
  ifstream file(file_name);
  
  //file.eof() do an extra read when all lines are read
  //getline returns false when there is not any line to read
  while(getline(file, value, ',')) {
    apuesta.tipo = stoi(value);
    getline(file, value, ',');
    apuesta.valor = value;
    getline(file, value);
    apuesta.cantidad = stoi(value);

    lapuesta.push_back(apuesta);
   }
  file.close();
  return lapuesta;
}
