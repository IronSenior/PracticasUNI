//dados.cc
//Cuerpo de los métodos de la clase Dados
#include "dados.h"
#include <cstdlib>
#include <ctime>
#include <list>

using std::list;

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
	savelanzamiento1_(d1_);
	savelanzamiento2_(d2_);
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

//Guarda en la lista de lanzamientos el ultimo del dado 1
void Dados::savelanzamiento1_(int lanz){
	if (vultimos1_.size() == 5){
		list<int>::iterator comienzo;
		comienzo = vultimos1_.begin();
		vultimos1_.remove(*comienzo);
	}
	vultimos1_.push_back(lanz);

}

//Guarda en la lista de lanzamientos el ultimo del dado 2
void Dados::savelanzamiento2_(int lanz){
	if (vultimos2_.size() == 5){
		list<int>::iterator comienzo;
		comienzo = vultimos2_.begin();
		vultimos2_.remove(*comienzo);
	}
	vultimos2_.push_back(lanz);

}