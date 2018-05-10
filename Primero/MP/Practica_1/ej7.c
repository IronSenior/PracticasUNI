#include <stdio.h>
#include <math.h>

/* En este ejercicio se pide lo siguiente
Codifica una función denominada estadisticasVector que reciba un vector de enteros y calcule,
usando paso de parámetros por referencia, la media, la varianza y la desviación típica de los
datos del vector. Implementa un programa que mediante funciones lea un vector de enteros, lo
imprima por pantalla, calcule las estadísticas y finalmente muestre los resultados.
*/

void estadisticasVector(int tmo, int v[], float *media, float *dt, float *vari){
  //Calcula la media
  for(int i=0; i<tmo; i++){
    *media += v[i];
  }
  *media = *media / tmo;

  //Calcula la varianza
  for(int i=0; i<tmo; i++){
    *vari += v[i]*v[i];
  }
  *vari = (*vari/tmo) - (*media*(*media));

  //Calcula la desviación típica
  *dt = sqrt(*vari);
}

int main(int argc, char const *argv[]) {
  int tmo;
  float media=0, dt=0, vari=0;

  printf("Introduzca el tamaño del vector\n");
  scanf("%i", &tmo);

  int v[tmo];

  for (int i=0; i<tmo; i++){
    printf("Introduzca valor\n");
    scanf("%i", &v[i]);
  }
  estadisticasVector(tmo, v, &media, &dt, &vari);
  printf("La media de los elementos es %f\n", media);
  printf("La desviacion tipica de los elementos es %f\n", dt);
  printf("La varianza de los elementos es %f\n", vari);
  return 0;
}
