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
  Grafo<G_Nodo, G_Lado> _grafo;
public:

  AlgoritmosGrafos(int numeroNodos, const Grafo<G_Nodo, G_Lado> &g){
    // Reserva memoria para la matriz de distancias
    _numeroNodos = numeroNodos;
    _grafo = g;
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

  void Floyd(){
    G_Nodo aux_nodo;

    for(int i=0; i < _numeroNodos; i++){
      for (int j=0; j < _numeroNodos; j++){
        for (int k=0; k < _numeroNodos; k++){
          if ((_distancias[j][i] + _distancias[i][k]) < _distancias[j][k]){
            _distancias[j][k] = _distancias[j][i] + _distancias[i][k];
            _recorridos[j][k] = _recorridos[j][i];
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

  void imprimeCamino(string ciudadSalida, string ciudadLlegada){
    int indexSalida = 0;
    int indexSalidaPrimera = 0;
    int indexLlegada = 0;
    bool encontrado = false;
    int distancia = 0;
    string camino = ciudadSalida;
    
    for(int i=0; i< _numeroNodos; i++){
      if(ciudadSalida == _grafo.getNodo(i)){
        indexSalidaPrimera = i;
      }
    }

    while(! encontrado){
      for(int i=0; i< _numeroNodos; i++){
        if(ciudadSalida == _grafo.getNodo(i)){
          indexSalida = i;
        }
        if(ciudadLlegada == _grafo.getNodo(i)){
          indexLlegada = i;
        }
      }
      if(_recorridos[indexSalida][indexLlegada] == ciudadLlegada){
        encontrado = true;
      }
      camino = camino + "-" + _recorridos[indexSalida][indexLlegada];
      ciudadSalida = _recorridos[indexSalida][indexLlegada];

    }
    distancia = _distancias[indexSalidaPrimera][indexLlegada];
    cout<<"El camino es: "<<camino<<endl;
    cout<<"La distancia es: "<<distancia<<endl;
  }

};

#endif
