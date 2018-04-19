#include <stdio.h>
#include <math.h>

void estadisticasVector(int tmo, int v[], float *media, float *dt, float *vari){
  for(int i=0; i<tmo; i++){
    *media += v[i];
  }
  *media = *media / tmo;
  for(int i=0; i<tmo; i++){
    *vari += v[i]*v[i];
  }
  *vari = (*vari/tmo) - (*media*(*media));
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
