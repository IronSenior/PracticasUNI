//funciones.c
//Fichero con todas las funcionalidades del juego (Menu y opciones)
#include "dados.h"
#include "funciones.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>


void accion_func(int eleccion, Dados d){
	switch(eleccion){
		case 0: { //Elección erronia
			std::cout<<"No has elegido ninguna acción\n\n";
			menu_func(d);
		}
		case 1: { //Llamada a la funcion de lanzamiento() de la clase Dados
			d.lanzamiento();
			std::cout<<"Lanzamiento realizado con éxito\n";
			menu_func(d);
		}
		case 2: { //Llamada a la función getDado1() de la clase Dados
			std::cout<<"El valor del dado 1 es "<<d.getDado1()<<std::endl;
			menu_func(d);
		}
		case 3: { //Llamada a la función getDado2() de la clase Dados
			std::cout<<"El valor del dado 2 es "<<d.getDado2()<<std::endl;
			menu_func(d);
		}
		case 4: { //Llamada a la función getSuma() de la clase Dados
			std::cout<<"El valor de la suma es "<<d.getSuma()<<std::endl;
			menu_func(d);
		}
		case 5: { //Llamada a la función serDado1() de la clase Dados
			int valor;
			std::cout<<"Introduzca el valor del dado 1\n";
			std::cin>>valor;
			d.setDado1(valor);
			menu_func(d);
		}
		case 6: { //Llamada a la función setDado2() de la clase Dados
			int valor;
			std::cout<<"Introduzca el valor del dado 2\n";
			std::cin>>valor;
			d.setDado2(valor);
			menu_func(d);
		}
		case 7:{ //Salir del programa
			exit(0);
		}
	}

}


//Menu principal
void menu_func(Dados d){
	int eleccion = 0;

	std::cout<<"\n\n\n";

	std::cout<<"Elige la acción a realizar\n";
	std::cout<<"1- Realizar lanzamiento\n";
	std::cout<<"2- Ver Dado 1\n";
	std::cout<<"3- Ver Dado 2\n";
	std::cout<<"4- Ver suma de los dados\n";
	std::cout<<"5- Set Dado 1\n";
	std::cout<<"6- Set Dadp 2\n";
	std::cout<<"7- Salir\n";

	std::cin>>eleccion;
	system("clear");

	accion_func(eleccion, d);
}
