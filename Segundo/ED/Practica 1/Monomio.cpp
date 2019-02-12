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
		assert((this->getCoeficiente() / m.getCoeficiente) == cofAux);
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
		assert((std::abs(this->getCoeficiente - 0.0)) > COTA_ERROR);
	#endif	

	this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
	this->setGrado(this->getGrado() + m.getGrado());

	#ifndef NDEBUG
		assert((gradAux - this->getGrado()) == m.getGrado());
		assert((this->getCoeficiente() * m.getCoeficiente) == cofAux);
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

	this->setCoeficiente(this->getCoeficiente() * x);
	
	#ifndef NDEBUG
		assert(this->getGrado() == gradAux);
		assert((this->getCoeficiente() * x) == cofAux);
	#endif

	// Se devuelve el objeto actual
	return *this;
}




///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

// COMPLETAR

