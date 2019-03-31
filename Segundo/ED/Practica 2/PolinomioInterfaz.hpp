/*!
   \file PolinomioInterfaz.hpp
   \brief Definición de la interfaz de la clase Polinomio
*/

#ifndef _POLINOMIOINTERFAZ_HPP_
#define _POLINOMIOINTERFAZ_HPP_

#include "Monomio.hpp"

// Se incluye la clase PolinomioInterfaz dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase PolinomioInterfaz
class PolinomioInterfaz
{

   //! \name Funciones o métodos públicos de la clase
   public:

	//! \name Observadores: funciones de consulta

	/**
	 * @brief Devuelve si el polinomio es nulo o no
	 * 
	 * @return true 
	 * @return false 
	 */
	virtual bool esNulo() const = 0;

  /**
   * @brief Devuelve el grado del polinomio
   * 
   * @return int 
   */
	virtual int getGrado() const = 0;

  /**
   * @brief Devuelve el numero de monomios por los que está formado el polinomio
   * 
   * @return int 
   */
	virtual int getNumeroMonomios() const = 0;


  /**
   * @brief DEvuelve si existe el monomio con grado n
   * 
   * @param n 
   * @return true 
   * @return false 
   */
	virtual bool existeMonomio(int n) const = 0;


  /**
   * @brief Devuelve el monomio de grado n
   * 
   * @param n 
   * @return ed::Monomio& 
   */
	virtual ed::Monomio & getMonomio(int n) = 0;



}; // Fin de la definición de la clase PolinomioInterfaz


} // \brief Fin de namespace ed.

//  _POLINOMIOINTERFAZ_HPP_
#endif
