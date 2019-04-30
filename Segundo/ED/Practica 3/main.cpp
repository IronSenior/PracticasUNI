#include <iostream>
#include <cstdlib> //para usar srand()
#include <cctype>

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "macros.hpp"
#include "generarpersona.hpp"

using namespace ed;

void pruebaMostrar(ArbolBinarioOrdenadoEnlazado<int> &a);
void pruebaBuscar(ArbolBinarioOrdenadoEnlazado<int> &a);
void pruebaBorrar(ArbolBinarioOrdenadoEnlazado<int> &a);
void pruebaBorrarArbol(ArbolBinarioOrdenadoEnlazado<int> &a);


int main()
{
  ArbolBinarioOrdenadoEnlazado<int> a;
  EscribirNodo<int> op;

  //int npersonas = 0;

  // Limpia la terminal completamente
  system("clear");

//  std::cout << BIBLUE;
//  std::cout<<"Introduzca el número de ints que quiere generar: ";
//  std::cout << RESET;
//  std::cout << BIGREEN;
//  std::cin>>nints;
//  std::cout << RESET;

  std::vector<int> pruebaProfesor{ 10, 5, 1, 9, 7, 6, 8, 20, 15, 25, 22, 27 };

  // Genera el arbol con el numero de ints pedido
  for(int i=0; i < 12; i++){
      a.insertar(pruebaProfesor[i]);
  }

  int opcion = 0;
  int posicion = 0;

  do{
      // Se muestran las opciones del menú
      posicion=2;

      // Se borra la pantalla
      system("clear");

      // Menu principal del programa
      std::cout << BIBLUE;
      std::cout << "Programa principal | Opciones del menú   \n\n";
      std::cout << RESET;

      posicion++;
      std::cout << "[1] Test de Imprimir arbol\n\n";

      std::cout << "[2] Test de busqueda\n\n";

      std::cout << "[3] Test de borrado de elemento\n\n";

      std::cout << "[4] Test de borrado del arbol\n\n";

      posicion++;
      std::cout << BIRED;
      std::cout << "[0] Fin del programa \n\n";
      std::cout << RESET;

      posicion++;
      std::cout << BIYELLOW;
      std::cout << "Opción: ";
      std::cout << RESET;
      std::cin >> opcion;

      // Seleccion de opcion
      std::cout<<opcion;
      switch (opcion)
      {
        case 1:
          pruebaMostrar(a);
          std::cin.ignore();
          break;
        case 2:
          pruebaBuscar(a);
          std::cin.ignore();
          break;
        case 3:
          pruebaBorrar(a);
          std::cin.ignore();
          break;
        case 4:
          pruebaBorrarArbol(a);
          std::cin.ignore();
          break;
      }

  }while(opcion != 0);

  return 0;

}


void pruebaMostrar(ed::ArbolBinarioOrdenadoEnlazado<int> &a){

  // Creacion del operador de escritura
  system("clear");
  EscribirNodo<int> op;

  std::cout<< BIPURPLE;
  std::cout<<"Prueba Mostrar\n\n";
  std::cout<< RESET;

  std::cout<< BIYELLOW;
  std::cout<<"PreOrden\n";
  a.recorridoPreOrden(op);
  std::cout<<"\n";
  std::cout<< RESET;

  std::cout<< BICYAN;
  std::cout<<"InOrden"<<std::endl;
  a.recorridoInOrden(op);
  std::cout<<"\n";
  std::cout<< RESET;

  std::cout<< BIWHITE;
  std::cout<<"PostOrden"<<std::endl;
  a.recorridoPostOrden(op);
  std::cout<<"\n";
  std::cout<< RESET;
  
  std::cin.ignore();
}

void pruebaBuscar(ArbolBinarioOrdenadoEnlazado<int> &a){
  system("clear");
  int aux_p;

  std::cout<< BIPURPLE;
  std::cout<<"Prueba de la funcion buscar\n\n";
  std::cout<< RESET;

  std::cout << BIBLUE;
  std::cout<<"Introduzca la int que quiere buscar\n";
  std::cout << RESET;
  std::cout << BIGREEN;
  std::cin>>aux_p;
  std::cout << RESET;

  if(a.buscar(aux_p)){
    std::cout << BIGREEN;
    std::cout<<"int encontrada\n";
    std::cout << RESET;
  }
  else{
    std::cout << BIRED;
    std::cout<<"int no encontrada\n";
    std::cout << RESET;
  }
  std::cin.ignore();
}

void pruebaBorrar(ArbolBinarioOrdenadoEnlazado<int> &a){

  // Creacion del operador de escritura
  system("clear");
  EscribirNodo<int> op;
  int aux_p;

  std::cout<< BIPURPLE;
  std::cout<<"Prueba de la funcion borrar\n\n";
  std::cout<< RESET;

  std::cout << BIBLUE;
  std::cout<<"Introduzca la int que quiere borrar\n";
  std::cout << RESET;
  std::cout << BIGREEN;
  std::cin>>aux_p;
  std::cout << RESET;

  //Busca primero para que el puntero actual quede ahí
  if (a.buscar(aux_p)){
      if (a.borrar()){
        std::cout << BIGREEN;
        std::cout<<"El elemento ha sido borrado\n";
        std::cout << RESET;
        std::cout << BICYAN;
        a.recorridoInOrden(op);
        std::cout << RESET;
      }
      else{
        std::cout << BIRED;
        std::cout<<"El elemento no ha sido borrado\n";
        std::cout << RESET;
        std::cout << BICYAN;
        a.recorridoInOrden(op);
        std::cout << RESET;
      }
  }
  else{
      std::cout << BIRED;
      std::cout<<"Elemento no encontrado\n";
      std::cout << RESET;
  }
  std::cin.ignore();
}

void pruebaBorrarArbol(ArbolBinarioOrdenadoEnlazado<int> &a){
  // Creacion del operador de escritura
  system("clear");
  EscribirNodo<int> op;

  std::cout<< BIPURPLE;
  std::cout<<"Prueba de la funcion borrarArbol\n\n";
  std::cout<< RESET;

  // Borrado del arbol
  if (! a.estaVacio()){
    a.borrarArbol();
  }

  // Comprobacion del resultado de borrar
  if (a.estaVacio()){
    std::cout << BIGREEN;
    std::cout<<"El arbol ha sido borrado"<<std::endl;
    std::cout << RESET;
    exit(0);
  }
  else{
    std::cout << BIRED;
    std::cout<<"Error en el borrado completo del arbol"<<std::endl;
    std::cout << RESET;

    std::cout << BICYAN;
    a.recorridoInOrden(op);
    std::cout << RESET;
  }
  std::cin.ignore();

}