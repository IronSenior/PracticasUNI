#include <stdio.h>
#include <string.h>

//Este ejercico te pide implemtar un programa que detecte si una cadena es prefijo o no de otra cadena
//ESTÄ SIN TERMINAR

int es_prefijo(char cadena, char prefijo){
  printf("Hola he entrado\n");
  //int tmnpref = sizeof(prefijo);
  printf("%s\n", prefijo);
  return 1;

}

int main(int argc, char const *argv[]) {
  char *prueba;
  printf("Introduzca la palabra\n");
  scanf("%s",prueba);
  
  char *pref;
  printf("Introduzca el prefijo a comprobar\n");
  scanf("%s", pref);



  if (es_prefijo(*prueba, *pref)){
    printf("Si es prefijo\n");
  }
  else{
    printf("No es prefijo");
  }

  return 0;
}
