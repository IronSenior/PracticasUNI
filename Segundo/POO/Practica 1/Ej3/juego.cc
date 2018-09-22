//juego.cc
// Programa principal prueba funcionamiento de la clase Dados
#include <iostream>
#include "dados.h"

int main(int argc, char const *argv[]){
	Dados d;
	int eleccion;

	std::cout<<"Bienvenido a 'El juego de los DADOS'\n";
	eleccion = menu_func();


	std:cin>>eleccion;


	return 0;
}
//Funcion para llamar al menu
int menu_func(){
	int eleccion = 0;

	std::cout<<"Elige la acción a realizar\n";
	std::cout<<"1- Realizar lanzamiento\n";
	std::cout<<"2- Ver Dado 1\n";
	std::cout<<"3- Ver Dado 2\n";
	std::cout<<"4- Ver suma de los dados\n";
	std::cout<<"5- Set Dado 1\n";
	std::cout<<"6- Set Dadp 2\n";

	accion_func(eleccion);
}

//Funcion en la que se realizan las acciones
void accion_func(int eleccion){
	switch(eleccion){
		case 0: {
			std::cout<<"No has elegido ninguna acción\n\n";
			menu_func();
		}
		case 1: {
			Dados::lanzamiento();
			std::cout<<"Lanzamiento realizado con éxito\n";
		}
		case 2: {
			std::cout<<"El valor del dado 1 es "<<Dados::getDado1()<<endl;
		}
		case 3: {
			std::cout<<"El valor del dado 2 es "<<Dados::getDado2()<<endl;
		}
		case 4: {
			std::cout<<"El valor de la suma es "<<Dados::getSuma()<<endl;
		}
		case 5: {
			int valor;
			std::cout<<"Introduzca el valor del dado 1\n";
			std::cin>>valor;
			boolDados::setDado1(valor);
			if 
		}
		case 6: {
			int valor;
			std::cout<<"Introduzca el valor del dado 2\n";
			std::cin>>valor;
			Dados::setDado2(valor);
		}
	}

}