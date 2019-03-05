/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed
{
//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
class Monomio
{
	//! \name Atributos privados de la clase Monomio
	//! \privatesection
	private:
		double coeficiente_;
		int grado_;

	//! \name Funciones o métodos públicos de la clase Monomio
	//! \publicsection
	public:
	//! \name Constructores de la clase Monomio
		//Constructor
		Monomio(double coeficiente=0.0, int grado=0){
			#ifndef NDEBUG
				assert(grado >= 0);
			#endif

			this->setCoeficiente(coeficiente);
			this->setGrado(grado);

			#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
				assert(this->getGrado() == grado);
			#endif

		}

		//Constructor de copia
		Monomio(Monomio &monomio){
			this->setCoeficiente(monomio.getCoeficiente());
			this->setGrado(monomio.getGrado());

			#ifndef NDEBUG
				assert(std::abs(monomio.getCoeficiente() - this->getCoeficiente()) < COTA_ERROR);
				assert(monomio.getGrado() == this->getGrado());
			#endif
		}


	//! \name Observadores: funciones de consulta de la clase Monomio
		inline double getCoeficiente() const {return coeficiente_;};

		inline int getGrado() const {return grado_;};


	//! \name Funciones de modificación de la clase Monomio

		//Aunque en principio no parezcan funciones inline, al compilar sin asserts lo seran
		inline void setCoeficiente(double coeficiente){
			coeficiente_ = coeficiente;

			#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - coeficiente) < COTA_ERROR);
			#endif
		};

		inline void setGrado(int grado){
			#ifndef NDEBUG
				assert(grado >= 0);
			#endif

			grado_ = grado;

			#ifndef NDEBUG
				assert(this->getGrado() == grado);
			#endif
			
		};


	/////////////////////////////////////////////////

	//! \name Operadores de la clase Monomio

	// Operadores de asignación

		//! \name Asignación de monomio a monomio
		Monomio & operator=(Monomio const &m);

		//! \name Asignación de real a monomio
		Monomio & operator=(double const &x);


	// Operadores aritméticos y asignación

		//! \name Operadores aritméticos y asignación
		Monomio & operator+=(Monomio const &m);

		Monomio & operator-=(Monomio const &m);

		Monomio & operator*=(Monomio const &m);

		Monomio & operator/=(Monomio const &m);

		Monomio & operator*=(double const &x);

		Monomio & operator/=(double const &x);

	/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Monomio
		void leerMonomio();

		void escribirMonomio();

	///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Monomio
		double calcularValor(double x);



};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
