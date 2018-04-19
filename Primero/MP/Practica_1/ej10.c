#include <stdio.h>

void leeVector(double v[], int *tmn){
  for(int i=0; i<*tmn; i++){
    printf("Introduzca elemento del vector\n");
    scanf("%lf", &v[i]);
  }
}
void escribeVector(double v[], int *tmn){
  for(int i=0; i<*tmn; i++){
    printf("%lf\n", v[i]);
  }
}
void sumaPositivos(double v[], double *total, int *tmn){
  for(int i=0; i<*tmn; i++){
    if (v[i]>0){
      *total = *total + v[i];
    }
  }
  printf("El total de la suma es %lf\n", *total);
}

int main(int argc, char const *argv[]) {
  int tmn;
  double total = 0;

  printf("Introduzca el número de elementos que tendrá el vector\n");
  scanf("%i", &tmn);
  double v[tmn];

  leeVector(v, &tmn);
  escribeVector(v, &tmn);
  sumaPositivos(v, &total, &tmn);
  return 0;
}
