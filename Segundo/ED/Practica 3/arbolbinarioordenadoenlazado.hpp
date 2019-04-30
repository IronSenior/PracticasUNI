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
			// Constructor
			NodoArbolBinario (const G &info)
			{
				// Establece el dato e inicializa los punteros a NULL
				this->setInfo(info);
				_izquierdo = NULL;
				_derecho = NULL;

				// Se asegura de que una vez creado no tiene hijos
				#ifndef NDEBUG
					assert(this->esHoja());
				#endif
			}

			// Constructor de copia
			NodoArbolBinario (const NodoArbolBinario &n)
			{
				*this = n;

				// Se asegura de que la copia ha sido correcta
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
				// Si no tienen ni hijo izquierdo ni derecho, significa que es hoja
				if((this->getDerecho() != NULL)||(this->getIzquierdo() != NULL)){
					return false;
				}
				return true;
			}

			// Recorrido PreOrden
			void recorridoPreOrden (OperadorNodo<G> &operador) const
			{	
				// Se aplica en el nodo antes que en los hijos (si los tiene)
				operador.aplicar(this->getInfo());
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo()->recorridoPreOrden(operador);
				}	
				if(this->getDerecho() != NULL){
					this->getDerecho()->recorridoPreOrden(operador);
				}
			}

			// Recorrido PostOrden
			void recorridoPostOrden (OperadorNodo<G> &operador) const
			{
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo()->recorridoPostOrden(operador);
				}	
				if(this->getDerecho() != NULL){
					this->getDerecho()->recorridoPostOrden(operador);
				}
				// Se aplica en el nodo despues que en los hijos (si los tiene)
				operador.aplicar(this->getInfo());	
			}

			// Recorrido InOrden
			void recorridoInOrden (OperadorNodo<G> &operador) const
			{
				if(this->getIzquierdo() != NULL){
					this->getIzquierdo()->recorridoInOrden(operador);
				}
				// Se aplica en el nodo entre medias de los hijos (si los tiene)
				operador.aplicar(this->getInfo());
				if(this->getDerecho() != NULL){
					this->getDerecho()->recorridoInOrden(operador);
				}
			}

			/*!\brief Modificadores. */
			void setInfo(const G &info)
			{
				_info = info;
			}

			void setIzquierdo(NodoArbolBinario *n)
			{
				_izquierdo = n;
			}

			void setDerecho(NodoArbolBinario *n)
			{
				_derecho = n;
			}

			// Operador de asignación (Ayuda en el constructor de copia)
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

		// Constructor
		ArbolBinarioOrdenadoEnlazado ()
		{
			// Inicializa todos los punteros a NULL
			_raiz = NULL;
			_actual = NULL;
			_padre = NULL;

			// Comprueba que se han inicializado correctamente
			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif
		}

		// Constructor de copia
		ArbolBinarioOrdenadoEnlazado (const ArbolBinarioOrdenadoEnlazado<G>& a)
		{
			*this = a;
		}

		// Destructor
		~ArbolBinarioOrdenadoEnlazado ()
		{
			if (not this->estaVacio())
			borrarArbol();
			cout << "Destructor Usado \n";
		}

		// Operador de asignacion
		ArbolBinarioOrdenadoEnlazado &operator=(const ArbolBinarioOrdenadoEnlazado& a)
		{
			this->_raiz = a._raiz;
			this->_actual = a._actual;
			this->_padre = a._padre;
		}

		// Inserta un nuevo nodo en el arbol
		bool insertar(const G &x)
		{
			// La variable inserted será el return de la funcion
			bool inserted = false;

			// Si está vacio se inserta en la raiz
			if (this->estaVacio()){
				_raiz = new NodoArbolBinario(x);
				inserted = true;
			}
			// Si no buscara donde insertarse hasta hacerlo
			else{
				_padre = NULL;
				_actual = _raiz;
			}
			while (! inserted){
				// Si el que queremos insertar es mayor que donde estamos, nos moveremos a la derecha
				if (x > this->actual()){
					if (_actual->getDerecho() != NULL){
						_padre = _actual;
						_actual = _actual->getDerecho();
					}
					else{
						_actual->setDerecho(new NodoArbolBinario(x));
						inserted = true;
					}
				}
				// Si el que queremos insertar es menor que donde estamos, nos moveremos a la izquierda
				else{
					if (_actual->getIzquierdo() != NULL){
						_padre = _actual;
						_actual = _actual->getIzquierdo();
					}
					else{
						_actual->setIzquierdo(new NodoArbolBinario(x));
						inserted = true;
					}
				}

			}
			
			return inserted;
		}


		// BorrarArbol establece la raiz a NULL
		void borrarArbol()
		{
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif

			_raiz = NULL;
			_actual = NULL;
			_padre = NULL;

			#ifndef NDEBUG
				assert(this->estaVacio());
			#endif
		}

		// Borra el nodo apuntado por el puntero actual
		bool borrar()
		{
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif

			// Guarda el puntero padre y actual en una variable auxiliar
			NodoArbolBinario *aux_pt_actual;
			NodoArbolBinario *aux_pt_padre;
			aux_pt_actual = _actual;
			aux_pt_padre = _padre;

			// La variable borrado será el return de esta funcion
			bool borrado = false;

			// El algoritmo sustituirá el nodo por el menor de sus mayores o el mayor de sus menores
			// Para ello se moverá uno a la derecha (si es posible) y todo a la izquierda
			if(_actual->getDerecho() != NULL){
				_padre = _actual;
				_actual = _actual->getDerecho();

				while(_actual->getIzquierdo() != NULL){
					_padre = _actual;
					_actual = _actual->getIzquierdo();
				}

				// Despues de haber llegado hasta el objetivo se intercambian los hijos para no perder informacion
				if(_actual->getInfo() < _padre->getInfo()){
					_padre->setIzquierdo(_actual->getDerecho());
				}
				else{
					aux_pt_actual->setDerecho(_actual->getDerecho());
				}
				aux_pt_actual->setInfo(_actual->getInfo());
				borrado = true;

				// Se devuelven los punteros a su origen
				_actual = aux_pt_actual;
				_padre = aux_pt_padre;
			}
			// O se moverá uno a la izquierda y todo a la derecha
			else if (_actual->getIzquierdo() != NULL){
				_padre = _actual;
				_actual = _actual->getIzquierdo();

				while(_actual->getDerecho() != NULL){
					_padre = _actual;
					_actual = _actual->getDerecho();
				}

				// Despues de haber llegado hasta el objetivo se intercambian los hijos para no perder informacion
				if(_actual->getInfo() > _padre->getInfo()){
					_padre->setDerecho(_actual->getIzquierdo());
				}
				else{
					aux_pt_actual->setIzquierdo(_actual->getIzquierdo());
				}
				aux_pt_actual->setInfo(_actual->getInfo());
				borrado = true;

				// Se devuelven los punteros a su origen
				_actual = aux_pt_actual;
				_padre = aux_pt_padre;

			}
			// Caso especial en el que el nodo es hoja o es la raiz
			else{
				if (_raiz == _actual){
					this->borrarArbol();
				}
				else if(_actual->getInfo() < _padre->getInfo()){
					_padre->setIzquierdo(NULL);
				}
				else{
					_padre->setDerecho(NULL);
				}
				borrado = true;
			}
			return borrado;
		}

		// Llama al recorrido preOrden de la raiz
		void recorridoPreOrden (OperadorNodo<G> &operador) const
		{
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif
			_raiz->recorridoPreOrden(operador);
		}

		// Llama al recorrido postOrden de la raiz
		void recorridoPostOrden (OperadorNodo<G> &operador) const
		{
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif
			_raiz->recorridoPostOrden(operador);
		}

		// Llama al recorrido inOrden de la raiz
		void recorridoInOrden (OperadorNodo<G> &operador) const
		{
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif
			_raiz->recorridoInOrden(operador);
		}

		// Busca el nodo que tenga x como info
		bool buscar(const G& x) //No puede ser const porque hay que modificar el puntero
		{
			// La variable encontrado será el return de esta funcion
			bool encontrado = false;
			_padre = NULL;
			_actual = _raiz;

			// Mientras no lo encuentre buscará
			// Buscará hacia la izquierda si el nodo buscado esmenor que el actual
			while((_actual != NULL)&&(! encontrado)){
				if (_actual->getInfo() > x){
					if (_actual->getIzquierdo() != NULL){
						_padre = _actual;
						_actual = _actual->getIzquierdo();
					}
					else{
						_actual = NULL;
					}
				}
				// Buscara hacia la derecha si el nodo es mayor que el actual
				else if(_actual->getInfo() < x){
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

		// Comprueba si la raiz es NULL
		bool estaVacio() const
		{
			if (_raiz == NULL){
				return true;
			}
			return false;
		}

		// Devuelve la info del nodo raiz
		G raiz() const
		{
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif

			return _raiz->getInfo();
		}

		// Devuelve el true si el nodo actual es distinto de Null
		bool existeActual() const
		{
			#ifndef NDEBUG
				assert(! this->estaVacio());
			#endif

			if (_actual == NULL){
				return false;
			}
			return true;
		}

		// Devuelve la info del nodo actual
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
