#include <stdio.h>

int minimo(int num1,int num2){
  if (num1<num2){
    return num1;
  }
  else{
    return num2;
  }
}

int minimo2(int num1, int num2, int * resultado){
  if (num1<num2){
    *resultado = num1;
  }
  else{
    *resultado = num2;
  }
}


int main(void){
  int num1 = 1;
  int num2 = 2;
  int resultado = 0;

  printf("Introduzca dos numeros\n");
  scanf("%d", &num1);
  scanf("%d", &num2);

  int min = minimo(num1, num2);
  minimo2(num1, num2, &resultado);

  printf(" - Minimo por versión 1: %d\n", min);
  printf(" - Minimo por versión 2: %d\n", resultado);

  return 0;

}
