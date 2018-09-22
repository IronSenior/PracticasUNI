//juego.cc
// Programa principal prueba funcionamiento de la clase Dados
#include <iostream>
#include "dados.h"
#include "funciones.h"

int main(int argc, char const *argv[]){
	Dados d;
	int eleccion;

	std::cout<<"Bienvenido a 'El juego de los DADOS'\n";
	eleccion = menu_func(d);

	std::cout<<"Proceso terminado";

	return 0;
}
