//funciones.c
//Funcion en la que se realizan las acciones
#include "dados.h"
#include "funciones.h"
#include <iostream>

void accion_func(int eleccion, Dados d){
	switch(eleccion){
		case 0: {
			std::cout<<"No has elegido ninguna acción\n\n";
			menu_func(d);
		}
		case 1: {
			d.lanzamiento();
			std::cout<<"Lanzamiento realizado con éxito\n";
			menu_func(d);
		}
		case 2: {
			std::cout<<"El valor del dado 1 es "<<d.getDado1()<<std::endl;
			menu_func(d);
		}
		case 3: {
			std::cout<<"El valor del dado 2 es "<<d.getDado2()<<std::endl;
			menu_func(d);
		}
		case 4: {
			std::cout<<"El valor de la suma es "<<d.getSuma()<<std::endl;
			menu_func(d);
		}
		case 5: {
			int valor;
			std::cout<<"Introduzca el valor del dado 1\n";
			std::cin>>valor;
			d.setDado1(valor);
			menu_func(d);
		}
		case 6: {
			int valor;
			std::cout<<"Introduzca el valor del dado 2\n";
			std::cin>>valor;
			d.setDado2(valor);
			menu_func(d);
		}
		case 7:{
			exit(0);
		}
	}

}
//Funcion para llamar al menu
int menu_func(Dados d){
	int eleccion = 0;

	std::cout<<"Elige la acción a realizar\n";
	std::cout<<"1- Realizar lanzamiento\n";
	std::cout<<"2- Ver Dado 1\n";
	std::cout<<"3- Ver Dado 2\n";
	std::cout<<"4- Ver suma de los dados\n";
	std::cout<<"5- Set Dado 1\n";
	std::cout<<"6- Set Dadp 2\n";
	std::cout<<"7- Salir\n";

	accion_func(eleccion, d);
}
