/*! 
   \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad
	bool operator==(ed::Monomio const &m1, ed::Monomio const &m2){
		if ((m1.getCoeficiente() == m2.getCoeficiente()) and (std::abs(m1.getGrado() - m2.getGrado()) < COTA_ERROR)){
			return true;
		}
		return false;
	}

	bool operator==(ed::Monomio const &m, double x){
		if ((m.getGrado() < COTA_ERROR) and (std::abs(x - m.getCoeficiente()) < COTA_ERROR)){
			return true;
		}
		return false;
	}

	bool operator==(double x, ed::Monomio const &m){
		if ((m.getGrado() < COTA_ERROR) and (std::abs(x - m.getCoeficiente()) < COTA_ERROR)){
			return true;
		}
		return false;
	}


	// Operadores de desigualdad
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2)
	{
		if ((m1.getCoeficiente() == m2.getCoeficiente()) and (std::abs(m1.getGrado() - m2.getGrado()) < COTA_ERROR)){
			return false;
		}
		return true;
	}

	bool operator!=(ed::Monomio const & m, double x){
		if ((m.getGrado() < COTA_ERROR) and (std::abs(x - m.getCoeficiente()) < COTA_ERROR)){
			return false;
		}
		return true;
	}

	bool operator!=(double x, ed::Monomio const & m){
		if ((m.getGrado() < COTA_ERROR) and (std::abs(x - m.getCoeficiente()) < COTA_ERROR)){
			return false;
		}
		return true;
	}


	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	// COMPLETAR
	ed::Monomio & operator+(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		*nuevo = m;

		// Se devuelve el resultado
		return *nuevo;
	}

	// COMPLETAR
	ed::Monomio & operator-(ed::Monomio const & m)
	{
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio();

		*nuevo = m;
		nuevo->setCoeficiente(-(nuevo->getCoeficiente()));

		// Se devuelve el resultado
		return *nuevo;
	}



	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(std::abs(m1.getGrado() - m2.getGrado()) < COTA_ERROR);
		#endif

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() + m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
	
		#ifndef NDEBUG
			assert(std::abs(m1.getGrado() - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs((m1.getCoeficiente() + m2.getCoeficiente()) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	////////////
	// Resta
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		#ifndef NDEBUG
			assert(std::abs(m1.getGrado() - m2.getGrado()) < COTA_ERROR);
		#endif

		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m1.getCoeficiente() - m2.getCoeficiente());
		nuevo->setGrado(m1.getGrado());
	

		#ifndef NDEBUG
			assert(std::abs(m1.getGrado() - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs((m1.getCoeficiente() - m2.getCoeficiente()) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}


	//////////////////
	// Multiplicación
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente((m1.getCoeficiente())*(m2.getCoeficiente()));
		nuevo->setGrado(m1.getGrado() + m2.getGrado());
	
		#ifndef NDEBUG
			assert(std::abs((m1.getGrado() + m2.getGrado()) - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs(((m1.getCoeficiente()) *(m2.getCoeficiente())) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m, double x)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente()*x);
		nuevo->setGrado(m.getGrado());
	
		#ifndef NDEBUG
			assert(std::abs(m.getGrado() - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs((m.getCoeficiente() * x) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator* (double x, ed::Monomio const &m)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente()*x);
		nuevo->setGrado(m.getGrado());
	
		#ifndef NDEBUG
			assert(std::abs(m.getGrado() - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs((m.getCoeficiente() * x) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	////////////
	// División
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente((m1.getCoeficiente())/(m2.getCoeficiente()));
		nuevo->setGrado(m1.getGrado() - m2.getGrado());
	
		#ifndef NDEBUG
			assert(std::abs((m1.getGrado() - m2.getGrado()) - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs(((m1.getCoeficiente())/(m2.getCoeficiente())) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m, double x)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente()/x);
		nuevo->setGrado(m.getGrado());
	
		#ifndef NDEBUG
			assert(std::abs(m.getGrado() - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs((m.getCoeficiente() / x) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator/ (double x, ed::Monomio const &m)
	{
		ed::Monomio *nuevo = new ed::Monomio();

		nuevo->setCoeficiente(m.getCoeficiente()/x);
		nuevo->setGrado(m.getGrado());
	
		#ifndef NDEBUG
			assert(std::abs(m.getGrado() - nuevo->getGrado()) < COTA_ERROR);
			assert(std::abs((m.getCoeficiente() / x) - nuevo->getCoeficiente()) < COTA_ERROR);
		#endif

		// Se devuelve el resultado
		return *nuevo;
	}

	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) 
	{	
		int aux_Integer;
		double aux_Double;

		stream>>aux_Integer>>aux_Double;
		stream.ignore();

		m.setCoeficiente(aux_Integer);
		m.setGrado(aux_Double);
   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) 
	{
		stream<<m.getCoeficiente()<<" "<<m.getGrado();
		// Se devuelve el flujo de salida
		return stream;
	}


}  // namespace ed
