/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>
#include <list>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio: public ed::PolinomioInterfaz
{

  //! \name Atributos privados de la clase Polinomio
   private:

		std::list<Monomio> monomios_;


   //! \name Funciones o métodos públicos de la clase Polinomio
   public:
		//! \name Constructores de la clase Polinomio
		Polinomio(){
			Monomio nulo;
			nulo.setCoeficiente(0.0);
			nulo.setGrado(0);
			this->InsertaMonomio(nulo);
		};

		Polinomio(Polinomio const &copia){
			this->setMonomios(copia.getMonimios());
		};

		//! \name Observadores: funciones de consulta de la clase Polinomio
		inline std::list<Monomio> getMonimios() const {return monomios_;};

		//bool esNulo();

		int getGrado();

		inline int const getNumeroMonomios(){return this->getMonimios().size();};


		//! \name Funciones de modificación de la clase Polinomio
		inline void InsertaMonomio(Monomio &nuevo_monomio){this->monomios_.push_back(nuevo_monomio);};

		inline void setMonomios(std::list<Monomio> const &nueva_lista){this->monomios_ = nueva_lista;};

		////////////////////////////////////////////////////////////////

		//! \name Operadores de la clase Polinomio

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator=(Polinomio const &p);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator=(Monomio const &m);

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator=(double const &x);

		// Operadores aritméticos y asignación

		// COMPLETAR LOS COMENTARIOS DE DOXYGEN
		Polinomio & operator+=(Polinomio const &p);


		// COMPLETAR EL RESTO DE OPERADORES


		/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Polinomio

		// COMPLETAR


		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Polinomio

		// COMPLETAR


}; // Fin de la definición de la clase Polinomio




} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
