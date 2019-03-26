/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>

#include "Polinomio.hpp"

// Observadores
bool ed::Polinomio::esNulo() const {
	if (this->getNumeroMonomios() == 1){
		if ((this->getMonomios()[0].getGrado() == 0) && (std::abs(this->getMonomios()[0].getCoeficiente()) < COTA_ERROR)){
			return true;
		}
	}
	return false;
}

bool ed::Polinomio::existeMonomio(int mGrado) const{
	if (this->esNulo()){
		return false;
	}
	std::vector<Monomio>::iterator it;
	for (it = this->getMonomios().begin(); it != this->getMonomios().end(); it++){
		if (it->getGrado() == mGrado){
			return true;
		}
	}
}

ed::Monomio ed::Polinomio::getMonomio(int mGrado) const{
	if (! existeMonomio(mGrado)){
		Monomio aux(0.0, 0);
		return aux;
	}
	std::vector<Monomio>::iterator it;
	for (it = this->getMonomios().begin(); it != this->getMonomios().end(); it++){
		if (it->getGrado() == mGrado){
			return *it;
		}
	}
}

//Modificadores
void ed::Polinomio::InsertaMonomio(ed::Monomio const &nuevo_monomio){
	if (this->existeMonomio(nuevo_monomio.getGrado)){
		std::vector<Monomio>::iterator it;
		for (it = monomios_.begin(); it != monomios_.end(); it++){
			if(it->getGrado() == nuevo_monomio.getGrado()){
				*it += nuevo_monomio;
			}
		}
	}
	else{
		monomios_.push_back(nuevo_monomio);
		//this->ordenaPolinomio();
	}
}

// Operadores de asignación
/////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p)
{
	#ifndef NDEBUG
		assert(this->getMonomios() != p.getMonomios());
	#endif

	this->setMonomios(p.getMonomios());

	#ifndef NDEBUG
		assert(this->getMonomios() == p.getMonomios());
	#endif

	// Se devuelve el objeto actual
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m)
{
	std::vector<Monomio> aux_vector;
	aux_vector.push_back(m);

	this->setMonomios(aux_vector);

	#ifndef NDEBUG
		assert(this->getMonomios() == aux_vector);
	#endif
	return *this;
}


ed::Polinomio & ed::Polinomio::operator=(double const &x)
{
	std::vector<Monomio> aux_vector;
	ed::Monomio aux_monom(x, 0);
	aux_vector.push_back(aux_monom);

	this->setMonomios(aux_vector);

	#ifndef NDEBUG
		assert(this->getMonomios() == aux_vector);
	#endif

	// Se devuelve el objeto actual
	return *this;
}

//////////////////////////////////////////////////////////////

ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p)
{
	std::vector<Monomio>::iterator it;
	for (it = p.getMonomios().begin(); it != p.getMonomios().end(); it++){
		this->InsertaMonomio(*it);
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &m)
{
	this->InsertaMonomio(m);
	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &x)
{
	ed::Monomio aux(x, 0);
	this->InsertaMonomio(aux);
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p)
{
	ed::Monomio aux;
	std::vector<Monomio>::iterator it;
	for (it = p.getMonomios().begin(); it != p.getMonomios().end(); it++){
		aux.setCoeficiente(- it->getCoeficiente()); //OJO
		aux.setGrado(it->getGrado());
		this->InsertaMonomio(aux);
	}
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &m)
{
	ed::Monomio aux(-m.getCoeficiente(), m.getGrado()); //OJO
	this->InsertaMonomio(aux);
	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &x)
{
	ed::Monomio aux(-x, 0); //OJO
	this->InsertaMonomio(aux);
	return *this;
}


ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p)
{
	std::vector<Monomio>::iterator it;
	for (it = p.getMonomios().begin(); it != p.getMonomios().end(); it++){
		*this *= *it;
	}

	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &m)
{
	std::vector<Monomio> aux_vector = this->getMonomios();

	std::vector<Monomio>::iterator it;
	for (it = aux_vector.begin(); it != aux_vector.end(); it++){
		*it *= m;
	}

	this->setMonomios(aux_vector);
	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &x)
{
	ed::Monomio aux(x, 0); //OJO
	*this *= aux;
	return *this;
}


///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio

// COMPLETAR


///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio

// COMPLETAR
