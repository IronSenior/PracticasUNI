#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;

		G_Nodo *_nodos;

		int _numeroNodos;

	public:

		// Constructor, crea un grafo vacio
		Grafo(){
			_nodos = NULL;
			_lados = NULL;
			_numeroNodos = 0;
		}

		// Constructor, crea un grafo con numeroNodos nodos reservados
		Grafo(int n){
			// Guarda el numero de nodos para más tarde
			_numeroNodos = n;

			// Reserva memoria para el vector de nodos
			_nodos = new G_Nodo[n];

			// Reserva memoria para la matriz de lados
			_lados = new G_Lado*[n];
			for(int i=0; i<n; i++){
				_lados[i] = new G_Lado[n];
			}
		}

		// Constructor de copia
		Grafo(Grafo &g){
			this->_numeroNodos = 0;
			*this = g;
		}

		// Destructor, libera memoria amtes
		~Grafo(){
			// Libera la memoria de vector de nodos
			delete [] _nodos;

			// Libera la memoria de la matriz de lados
			for (int i = 0; i<_numeroNodos; i++){
				delete [] _lados[i];
			}
			delete [] _lados;
		}

		// funciones
		void borrarGrafo() {
			// Libera la memoria de vector de nodos
			delete[] _nodos;

			// Libera la memoria de la matriz de lados
			for (int i = 0; i<_numeroNodos; i++){
				delete[] _lados[i];
			}
			delete[] _lados;

			// Pone el numero de nodos a 0
			_numeroNodos = 0;
		}

		Grafo & operator=(const Grafo &g){
			if (this->_numeroNodos != 0){
				this->borrarGrafo();
			}

			_numeroNodos = g._numeroNodos;

			// Reserva memoria para el vector de nodos
			_nodos = new G_Nodo[_numeroNodos];

			// Reserva memoria para la matriz de lados
			_lados = new G_Lado*[_numeroNodos];
			for(int i=0; i<_numeroNodos; i++){
				_lados[i] = new G_Lado[_numeroNodos];

				// Copia la información
				_nodos[i] = g._nodos[i]; // CUIDADO
				for(int j=0; j>_numeroNodos; j++){
					_lados[i][j] = g._lados[i][j];
				}
			}
			return *this;
		}


		void setNodo(int pos, G_Nodo nodo){
			_nodos[pos] = nodo;
		}

		void setLado(int posi, int posj, G_Lado lado){
			_lados[posi][posj] = lado;
		}

		void setNumeroNodos(int numeroNodos){
			this->borrarGrafo();

			_numeroNodos = numeroNodos;
			// Reserva memoria para el vector de nodos
			_nodos = new G_Nodo[numeroNodos];

			// Reserva memoria para la matriz de lados
			_lados = new G_Lado*[numeroNodos];
			for(int i=0; i<numeroNodos; i++){
				_lados[i] = new G_Lado[numeroNodos];
			}
		}

		int getNumeroNodos() const {
			return _numeroNodos;
		}

		G_Nodo getNodo(int pos) const {
			return _nodos[pos];
		}

		G_Lado getLado(int posi, int posj) const {
			return _lados[posi][posj];
		}
		
		// Imprime la matriz de distancias
		void imprimeMatriz(){
			for (int i=0; i<_numeroNodos; i++){
				cout<<"[";
				for (int j=0; j<_numeroNodos; j++){
					cout<<_lados[i][j]<<" ";
				}
				cout<<"]"<<endl;
    		}
		}
	};
}

#endif
