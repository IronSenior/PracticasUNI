#include <iostream>
#include <cstdlib> //para usar srand()
#include <cctype>

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "macros.hpp"
#include "generarpersona.hpp"

using namespace ed;

void pruebaMostrar(ArbolBinarioOrdenadoEnlazado<Persona> &a);
void pruebaBuscar(ArbolBinarioOrdenadoEnlazado<Persona> &a);
void pruebaBorrar(ArbolBinarioOrdenadoEnlazado<Persona> &a);
void pruebaBorrarArbol(ArbolBinarioOrdenadoEnlazado<Persona> &a);


int main()
{
  ArbolBinarioOrdenadoEnlazado<Persona> a;
  Persona aux_p;
  EscribirNodo<Persona> op;

  int nPersonas = 0;

  // Limpia la terminal completamente
  system("clear");

  std::cout << BIBLUE;
  std::cout<<"Introduzca el número de personas que quiere generar: ";
  std::cout << RESET;
  std::cout << BIGREEN;
  std::cin>>nPersonas;
  std::cout << RESET;

  // Genera el arbol con el numero de personas pedido
  for(int i=0; i < nPersonas; i++){
    a.insertar(generarDatosPersonales());
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


void pruebaMostrar(ed::ArbolBinarioOrdenadoEnlazado<Persona> &a){

  // Creacion del operador de escritura
  system("clear");
  EscribirNodo<Persona> op;

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

void pruebaBuscar(ArbolBinarioOrdenadoEnlazado<Persona> &a){
  system("clear");
  Persona aux_p;

  std::cout<< BIPURPLE;
  std::cout<<"Prueba de la funcion buscar\n\n";
  std::cout<< RESET;

  std::cout << BIBLUE;
  std::cout<<"Introduzca la persona que quiere buscar\n";
  std::cout << RESET;
  std::cout << BIGREEN;
  std::cin>>aux_p;
  std::cout << RESET;

  if(a.buscar(aux_p)){
    std::cout << BIGREEN;
    std::cout<<"Persona encontrada\n";
    std::cout << RESET;
  }
  else{
    std::cout << BIRED;
    std::cout<<"Persona no encontrada\n";
    std::cout << RESET;
  }
  std::cin.ignore();
}

void pruebaBorrar(ArbolBinarioOrdenadoEnlazado<Persona> &a){

  // Creacion del operador de escritura
  system("clear");
  EscribirNodo<Persona> op;
  Persona aux_p;

  std::cout<< BIPURPLE;
  std::cout<<"Prueba de la funcion borrar\n\n";
  std::cout<< RESET;

  std::cout << BIBLUE;
  std::cout<<"Introduzca la persona que quiere borrar\n";
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

void pruebaBorrarArbol(ArbolBinarioOrdenadoEnlazado<Persona> &a){
  // Creacion del operador de escritura
  system("clear");
  EscribirNodo<Persona> op;

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