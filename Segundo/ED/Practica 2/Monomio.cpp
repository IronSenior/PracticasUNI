/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

// Operadores de asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m)
{
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());


	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
		assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
	#endif	

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator=(double const &x)
{
	this->setCoeficiente(x);
	this->setGrado(0);

	#ifndef NDEBUG
		assert(this->getGrado() == 0);
		assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR);
	#endif	

	// Se devuelve el objeto actual
	return *this;
}



//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

// COMPLETAR

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		double aux = this->getCoeficiente();
		assert(this->getGrado() == m.getGrado());
	#endif	

	this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

	#ifndef NDEBUG
		assert(this->getCoeficiente() - aux == m.getCoeficiente());
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		double aux = this->getCoeficiente();
		assert(this->getGrado() == m.getGrado());
	#endif	

	this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

	#ifndef NDEBUG
		assert(aux - this->getCoeficiente() == m.getCoeficiente());
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		double cofAux = this->getCoeficiente();
		int gradAux = this->getGrado();
	#endif	

	this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
	this->setGrado(this->getGrado() + m.getGrado());

	#ifndef NDEBUG
		assert(this->getGrado() - gradAux == m.getGrado());
		assert((this->getCoeficiente() / m.getCoeficiente()) == cofAux);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m)
{
	#ifndef NDEBUG
		double cofAux = this->getCoeficiente();
		int gradAux = this->getGrado();
		assert(this->getGrado() >= m.getGrado());
		assert(this->getCoeficiente() > COTA_ERROR);  // Coeficiente != 0
	#endif	

	this->setCoeficiente(this->getCoeficiente() / m.getCoeficiente());
	this->setGrado(this->getGrado() - m.getGrado());

	#ifndef NDEBUG
		assert((gradAux - this->getGrado()) == m.getGrado());
		assert((this->getCoeficiente() * m.getCoeficiente()) == cofAux);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator*=(double const &x)
{
	#ifndef NDEBUG
		double cofAux = this->getCoeficiente();
		int gradAux = this->getGrado();
	#endif	

	this->setCoeficiente(this->getCoeficiente() * x);
	
	#ifndef NDEBUG
		assert(this->getGrado() == gradAux);
		assert((this->getCoeficiente() / x) == cofAux);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator/=(double const &x)
{
	#ifndef NDEBUG
		double cofAux = this->getCoeficiente();
		int gradAux = this->getGrado();
	#endif	

	this->setCoeficiente(this->getCoeficiente() / x);
	
	#ifndef NDEBUG
		assert(this->getGrado() == gradAux);
		assert((this->getCoeficiente() * x) == cofAux);
	#endif

	// Se devuelve el objeto actual
	return *this;
}




///////////////////////////////////////////////////////////////////////

void ed::Monomio::leerMonomio(){

	int auxInteger;
	double auxDouble = 0;

	std::cout<<"Introduzca el coeficiente del monomio"<<std::endl;
	std::cin>>auxInteger;
	this->setCoeficiente(auxInteger);

	while(auxDouble < COTA_ERROR){
		std::cout<<"Introduzca el grado del monomio"<<std::endl;
		std::cin>>auxDouble;
	}
	this->setGrado(auxDouble);

	// Pausa
	std::cin.ignore();

	#ifndef NDEBUG
		assert(this->getGrado() >= 0);
	#endif
}


void ed::Monomio::escribirMonomio(){
	int coeficiente = this->getCoeficiente();
	double grado = this->getGrado();

	if (coeficiente != 1){
		std::cout<<coeficiente;
	}
	else if(coeficiente == -1){
		std::cout<<"-";
	}

	if (grado > COTA_ERROR){  // grado != 0
		std::cout<<"X";
		if(std::abs(grado - 1) > COTA_ERROR){  // grado != 1 
			std::cout<<"^"<<grado;
		}
	}
	std::cout<<std::endl;
}


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor(double x){
	int coeficiente = this->getCoeficiente();
	double grado = this->getGrado();
	double resultado;

	resultado = coeficiente*pow(x, grado);

	return resultado;
}

