#ifndef __ARBOLBINARIOORDENADO_HPP__
#define __ARBOLBINARIOORDENADOENLAZADO_HPP__

#include <iostream>
#include <cassert>
#include "arbolbinarioordenado.hpp"
#include "operadornodo.hpp"

using namespace std;
/*!
\brief Espacio de nombres para la asignatura Estructura de datos.
*/
namespace ed
{
	/*!\brief Interfaz para definir un ArbolBinario ordenado.

	Define una interfaz para definir un ArbolBinarioOrdenado.

	\arg G define el campo de información a contener en el arbol.
	\pre G debe tener definidos los operadores < y ==.
	*/
	template<class G>
	class ArbolBinarioOrdenadoEnlazado:public ArbolBinarioOrdenado<G>
	{
	private:

		/*!\brief Define un nodo del arbol binario.*/
		class NodoArbolBinario
		{
		private:
			G _info;  //Valor informativo almacenado en el nodo
			NodoArbolBinario * _izquierdo;  //Puntero al hijo izquierdo
			NodoArbolBinario * _derecho;  //Puntero al hijo derecho

		public:
			NodoArbolBinario (const G &info)
			{
				this->setInfo(info);

				#ifndef NDEBUG
					assert(this->esHoja());
				#endif
			}

			NodoArbolBinario (const NodoArbolBinario &n)
			{
				*this = n;

				#ifndef NDEBUG
					assert(this->getInfo() == n.getInfo());
					assert(this->getDerecho() == n.getDerecho());
					assert(this->getIzquierdo() == n.getIzquierdo());
				#endif
			}

			/*!\brief Observadores.*/
			const G & getInfo() const
			{
				return _info;
			}

			NodoArbolBinario *getIzquierdo() const
			{
				return _izquierdo;
			}

			NodoArbolBinario *getDerecho() const
			{
				return _derecho;
			}

			bool esHoja() const
			{
				if((this->getDerecho() != NULL)&&(this->getIzquierdo() != NULL)){
					return false;
				}
				return true;
			}

			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{
				operador.aplicar(*this);
				if(this->getDerecho() != NULL){
					this->getDerecho().recorridoPreOrden(operador);
				}
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo().recorridoPreOrden(operador);
				}		

			}

			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if(this->getDerecho() != NULL){
					this->getDerecho().recorridoPreOrden(operador);
				}
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo().recorridoPreOrden(operador);
				}	
				operador.aplicar(*this);	
			}

			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if(this->getDerecho() != NULL){
					this->getDerecho().recorridoPreOrden(operador);
				}
				operador.aplicar(*this);
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo().recorridoPreOrden(operador);
				}	
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				_izquierdo = *n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				_derecho = *n;
			}

			NodoArbolBinario & operator=(const NodoArbolBinario &n)
			{
				this->setInfo(n.getInfo());
				this->setDerecho(n.getDerecho());
				this->setIzquierdo(n.getIzquierdo());
			}

		}; //Fin clase NodoArbolBinario

		//Implementación de la raíz
		NodoArbolBinario * _raiz; /*!<La raiz del árbol*/
		NodoArbolBinario * _actual; /*!<Cursor al nodo actual*/
		NodoArbolBinario * _padre; /*!<Cursor al nodo padre actual*/

	public:

		ArbolBinarioOrdenadoEnlazado ()
		{
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif
		}

		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			*this = a;
		}

		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not this->estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			this->_raiz = a._raiz;
			this->_actual = a._actual;
			this->_padre = a._padre;
		}

		bool insertar(const G &x)
		{
			bool inserted = false;
			if (this->estaVacio()){
				_raiz = NodoArbolBinario(x);
				inserted = true;
			}
			else{
				_padre = NULL;
				_actual = raiz_;
			}
			while (! inserted){
				if (x > this->actual()){
					if (_actual->getDerecho() != NULL){
						_padre = _actual;
						_actual = _actual->getDerecho();
					}
					else{
						_actual->setDerecho(NodoArbolBinario(x));
						inserted = true;
					}
				}
				else{
					if (_actual->getIzquierdo() != NULL){
						_padre = _actual;
						_actual = _actual->getIzquierdo();
					}
					else{
						_actual->setIzquierdo(NodoArbolBinario(x));
						inserted = true;
					}
				}

			}
			
			return inserted;
		}

		void borrarArbol()
		{
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif

			_raiz = NULL;

			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif
		}

		bool borrar()
		{
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif

			NodoArbolBinario *aux_pt_actual;
			NodoArbolBinario *aux_pt_padre;
			aux_pt_actual = _actual;
			aux_pt_padre = _padre;
			bool borrado = flase;

			if(_actual->getDerecho() != NULL){
				_padre = _actual
				_actual = _actual->getDerecho();

				while(!_actual.esHoja()){
					_padre = _actual;
					_actual = _actual->getIzquierda()
				}

				aux_pt_actual->setInfo(_actual->getInfo());
				_padre.setIzquierdo(NULL);
				borrado = true;
			}
			else if (_actual->getIzquierdo() != NULL){
				_padre = _actual;
				_actual = _actual->getIzquiedo();

				while(!_actual.esHoja()){
					_padre = _actual;
					_actual = _actual->getderecho();
				}

				aux_pt->setInfo(_actual->getInfo());
				_padre.setDerecho(NULL);
				borrado = true;
			}
			else{
				this->borrarArbol();
				borrado = true;
			}

			_actual = aux_pt_actual;
			_padre = aux_pt_padre;

			return borrado;
		}

		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoPreOrden(operador);
		}

		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoPostOrden(operador);
		}

		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			_raiz->recorridoInOrden(operador);
		}

		bool buscar(const G& x) const
		{
			bool encontrado = false;
			_padre = NULL;
			_actual = _raiz;

			while((_actual != NULL)&&(! encontrado)){
				if (_actual->getInfo() > it){
					if (_actual->getIzquierdo() != NULL){
						_padre = _actual;
						_actual = _actual->getIzquierdo();
					}
					else{
						_actual = NULL;
					}
				}
				else if(_actual->getInfo() < it){
					if (_actual->getDerecho() != NULL){
						_padre = _actual;
						_actual = _actual->getDerecho();
					}
					else{
						_actual = NULL;
					}
				}
				else{
					encontrado = true;
				}
			}
			if (_actual == NULL){
				_padre = NULL;
				_actual = _raiz;
			}

			return encontrado;
		}

		bool estaVacio() const
		{
			if (_raiz == NULL){
				return true;
			}
			return false;
		}

		G raiz() const
		{
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif

			return _raiz->getInfo();
		}

		bool existeActual() const
		{
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif

			if (_actual == NULL){
				return false;
			}
			return true;
		}

		G actual() const
		{
			#ifndef NDEBUG
				assert(this->existeActual());
			#endif
			return _actual->getInfo();
		}

		/*!@}*/
	};

} //namespace ed

#endif //__ARBOLORDENADO_HPP__
