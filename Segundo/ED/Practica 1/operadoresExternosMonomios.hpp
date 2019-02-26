/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	bool operator==(ed::Monomio const & m, double x);

	bool operator==(double x, ed::Monomio const & m);


	//! \name Operadores de desigualdad 
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	bool operator!=(ed::Monomio const & m, double x);

	bool operator!=(double x, ed::Monomio const & m);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos
	ed::Monomio & operator+(ed::Monomio const & m);

	ed::Monomio & operator-(ed::Monomio const & m);


	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	ed::Monomio & operator* (ed::Monomio const &m, double x);

	ed::Monomio & operator* (double x, ed::Monomio const &m);

	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la división 
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	ed::Monomio & operator/ (ed::Monomio const &m, double x);

	ed::Monomio & operator/ (double x, ed::Monomio const &m);

	/////////////////////////////////////////////////////////////////////////////
	//! \name Sobrecarga de los operadores de entrada y salida 
	istream &operator>>(istream &stream, ed::Monomio &m);

	ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


