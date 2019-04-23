#include <iostream>
#include <cstdlib> //para usar srand()
#include <cctype>

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

using namespace ed;

int main()
{
  srand(time(0));

  ArbolBinarioOrdenadoEnlazado<Persona> a;
  Persona aux_p;
  EscribirNodo<Persona> op;

  int nPersonas = 3;

  std::cout<<"Introduzca el número de personas que quiere generar\n";
  std::cin>>nPersonas;

  for(int i=0; i < nPersonas; i++){
    a.insertar(generarDatosPersonales());
  }

  std::cout<<"Prueba Mostrar"<<std::endl;
  std::cout<<"PreOrden"<<std::endl;
  a.recorridoPreOrden(op);
  std::cout<<"InOrden"<<std::endl;
  a.recorridoInOrden(op);
  std::cout<<"PostOrden"<<std::endl;
  a.recorridoPostOrden(op);

  std::cout<<"Prueba de la funcion buscar"<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Introduzca la persona que quiere buscar"<<std::endl;
  std::cin>>aux_p;

  if(a.buscar(aux_p)){
    std::cout<<"Persona encontrada"<<std::endl;
    cout<<aux_p;
  }
  else{
    std::cout<<"Persona no encontrada"<<std::endl;
  }

  std::cout<<"Prueba de la funcion borrar"<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Introduzca la persona que quiere borrar"<<std::endl;
  std::cin>>aux_p;

  //Busca primero para que el puntero actual quede ahí
  if (a.buscar(aux_p)){
      if (a.borrar()){
        std::cout<<"El elemento ha sido borrado"<<std::endl;
        a.recorridoInOrden(op);
      }
      else{
        std::cout<<"El elemento no ha sido borrado"<<std::endl;
        a.recorridoInOrden(op);
      }
  }
  else{
      std::cout<<"Elemento no encontrado"<<std::endl;
  }

  std::cout<<"Prueba de la funcion borrarArbol"<<std::endl;
  std::cout<<std::endl;
  a.borrarArbol();
  if (a.estaVacio()){
    std::cout<<"El arbol ha sido borrado"<<std::endl;
  }
  else{
    std::cout<<"Error en el borrado completo del arbol"<<std::endl;
    a.recorridoInOrden(op);
  }


  return 0;

}
