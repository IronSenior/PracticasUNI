//juego.cc
// Programa principal prueba funcionamiento de la clase Dados
#include <iostream>
#include <cstdlib>
#include "dados.h"
#include "funciones.h"

int main(int argc, char const *argv[]){
	system("clear");
	Dados d;

	std::cout<<"Bienvenido a 'El juego de los DADOS'\n";
	menu_func(d);

	std::cout<<"El juego ha terminado\n";

	return 0;
}
