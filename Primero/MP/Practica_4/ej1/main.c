#include <stdio.h>
#include "funciones.h"


int main(int argc, char const *argv[]){

	float (*func) (float);
	int elec;

	//Menú de selección para la función matemática
	printf("Elija funcion\n");
	printf("0 --> f(x)\n");
	printf("1 --> g(x)\n");
	printf("2 --> z(x)\n");
	scanf("%d", &elec);
	
	//Asignación de puntero a función
	if (elec == 0)
		func = &f;
	else{
		if (elec == 1)
			func = &g;
		else
			func = &z;
	}

	//Pide N al usuario
	int n = 0;
	printf("Introduzca el valor de N\n");
	scanf("%d", &n);

	//Ejecuta la función e imprime el resultado 
	for (float i=0; i<n; i+=0.2){
		float resultado = (*func)(i);
		printf("El resultado para %f es %f\n", i, resultado);
	}
	return 0;
}
