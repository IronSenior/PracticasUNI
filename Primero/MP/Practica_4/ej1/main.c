#include <stdio.h>
#include <math.h>
//#include "funciones.h"

float g(float x){
	float resultado = 0;
	resultado = ((0-x)*sin(x))+1.5;
	return resultado;
}

int main(int argc, char const *argv[]){
	float resultado = 0;
	resultado = g(2);
	printf("%f\n", resultado);
	return 0;
}