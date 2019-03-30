/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

//Observadores
bool ed::Polinomio::esNulo(){
	Monomio aux_monom = this->getMonomios()[0];
	if((this->getNumeroMonomios() == 1) && (aux_monom.getGrado() == 0) && (std::abs(aux_monom.getCoeficiente()) < COTA_ERROR)){
		return true;
	}
	return false;

}


// Operadores de asignación

// COMPLETAR


/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	// COMPLETAR

	// Se devuelve el objeto actual
	return *this;
}

// COMPLETAR EL RESTO DE OPERADORES



///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio
 void ed::Polinomio::ordenarPolinomio(){
	Monomio aux_monom;
	aux_monom.setGrado(9999);

	std::vector<Monomio> aux_polinom;

	std::vector<Monomio>::iterator it;
	for (int i=0; i < this->getNumeroMonomios(); i++){
		for(it = this->getMonomios().begin(); it != this->getMonomios().end(); it++){
			if (it->getGrado() < aux_monom.getGrado()){
				aux_monom = *it;
			}
		}
		aux_polinom.push_back(aux_monom);
	}
 }
