#include <stdio.h>
#include <ctype.h>

void estadisticasCadena(char *cadena, int *mayus, int *minus, int *spac){
  int count = 0;
  while (cadena[count] != ('\0')) {
    if islower(cadena[count]){
      (*minus)++;
    }
    if isupper(cadena[count]){
      (*mayus)++;
    }
    if isspace(cadena[count]){
      (*spac)++;
    }
    count ++;
  }
}


int main(int argc, char const *argv[]) {
  char *cadena;
  int mayus=0, minus=0, spac=0;
  printf("Introduzca una cadena de texto\n");
  gets(cadena);
  printf("%s\n", cadena );
  estadisticasCadena(cadena, &mayus, &minus, &spac);

  printf("Hay %i minusculas en la cadena dada\n", minus);
  printf("Hay %i mayusculas en la cadena dada\n", mayus);
  printf("Hay %i espacios en la cadena dada\n", spac);
  return 0;
}
