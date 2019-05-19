#ifndef __ALGORITMOSGRAFOS_H__
#define __ALGORITMOSGRAFOS_H__
#include <iostream>

#include "grafo.hpp"
using namespace ed;
using namespace std;

template <class G_Nodo, class G_Lado>
class AlgoritmosGrafos
{
private:
  G_Lado **_distancias;
  G_Nodo **_recorridos;
  int _numeroNodos;
public:

  AlgoritmosGrafos(int numeroNodos, const Grafo<G_Nodo, G_Lado> &g){
    // Reserva memoria para la matriz de distancias
    _numeroNodos = numeroNodos;
    _distancias = new G_Lado*[numeroNodos];
    for(int i=0; i<numeroNodos; i++){
      _distancias[i] = new G_Lado[numeroNodos];
      for(int j=0; j<numeroNodos; j++){
        _distancias[i][j] = g.getLado(i, j);
      }
    }

    // Reserva memoria para la matriz de recorridos
    _recorridos = new G_Nodo*[numeroNodos];
    for(int i=0; i<numeroNodos; i++){
      _recorridos[i] = new G_Nodo[numeroNodos];
      for(int j=0; j<numeroNodos; j++){
        _recorridos[i][j] = g.getNodo(j);
      }
    }

    this->imprimeMatrices();
  }

  void Floyd(const Grafo<G_Nodo, G_Lado> &g){
    G_Nodo aux_nodo;

    for(int i=0; i < _numeroNodos; i++){      
      aux_nodo = g.getNodo(i);
      for (int j=0; j < _numeroNodos; j++){
        for (int k=0; k < _numeroNodos; k++){
          if ((_distancias[j][i] + _distancias[i][k]) < _distancias[j][k]){
            _distancias[j][k] = _distancias[j][i] + _distancias[i][k];
            _recorridos[j][k] = aux_nodo;
          }
        }
      }
    }
  }

  void imprimeMatrices(){
    cout<<"MATRIZ DE DISTANCIAS"<<endl;
    for (int i=0; i<_numeroNodos; i++){
      cout<<"[";
      for (int j=0; j<_numeroNodos; j++){
        cout<<_distancias[i][j]<<" ";
      }
      cout<<"]"<<endl;
    }
    cout<<endl;
    cout<<"MATRIZ DE RECORRIDOS"<<endl;
    for (int i=0; i<_numeroNodos; i++){
      cout<<"[";
      for (int j=0; j<_numeroNodos; j++){
        cout<<_recorridos[i][j]<< " ";
      }
      cout<<"]"<<endl;
    }
  }

};

#endif
