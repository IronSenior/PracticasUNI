//dados.cc
//Cuerpo de los métodos de la clase Dados
#include "dados.h"
#include <cstdlib>
#include <ctime>

Dados::Dados(){
	//Asigna los valores iniciales
	srand(time(NULL)); //time(NULL) returns "UNIX Epoch"
	d1_ = 1;
	d2_ = 1;
	lanzdado1_ = 0;
	lanzdado2_ = 0;
	d1Suma_ = 0;
	d2Suma_ = 0;

}

void Dados::lanzamiento(){
	//Simula un lazamiento de dados
	d1_  = (rand() % 6)+1;
	d2_ = (rand() % 6)+1;
	lanzdado1_ ++;
	lanzdado2_ ++;
	d1Suma_ += d1_;
	d2Suma_ += d2_;
}

int Dados::getDado1(){
	//Devuelve el valor del dado 1
	return d1_;
}

int Dados::getDado2(){
	//Devuelve el valor del dado 2
	return d2_;
}

bool Dados::setDado1(int valor){
	//Asigana un valor dado por el usuario al dado 1 (devuelve true si el dato es correcto)
	if ((0 < valor) && (valor < 7)){
		d1_ = valor;
		lanzdado1_ ++;
		d1Suma_ += d1_;
		return true;
	}
	else{
		return false;
	}
}

bool Dados::setDado2(int valor){
	//Asigana un valor dado por el usuario al dado 2 (devuelve true si el dato es correcto)
	if ((0 < valor) && (valor < 7)){
		d2_ = valor;
		lanzdado2_ ++;
		d2Suma_ += d2_;
		return true;
	}
	else{
		return false;
	}
}

int Dados::getSuma(){
	//Devuelve la suma de los dados
	int suma;
	suma = d1_ + d2_;
	return suma;
}
float Dados::getMedia1(){
	//Devuelve la media de todos los lanzamientos del dado 1
	if (lanzdado1_ == 0){
		return 0;
	}
	else{
		return (d1Suma_ / lanzdado1_);
	}
}
float Dados::getMedia2(){
	//Devuelve la media de todos los lanzamientos del dado 2
	if (lanzdado2_ == 0){
		return 0;
	}
	else{
		return (d2Suma_ / lanzdado2_);
	}
}
int Dados::getLanzamientos1(){
	//Decuelve el numero de veces que ha sido lanzado el dado 1
	return lanzdado1_;
}

int Dados::getLanzamientos2(){
	//Decuelve el numero de veces que ha sido lanzado el dado 2
	return lanzdado2_;
}
