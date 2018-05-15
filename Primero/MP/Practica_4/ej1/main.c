#include <stdio.h>
#include "funciones.h"
#include <math.h>

int main(int argc, char const *argv[]){
	float (*func) (float);
	int elec;

	//Menú de selección para la función matemática
	printf("¿Que funcion quiere aplicar?\n");
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

	//Pide x al usuario
	int x = 0;
	printf("Introduzca el valor entero de x\n");
	scanf("%d", &x);

	//Ejecuta la función e imprime el resultado
	float resultado = (*func)(x);
	printf("El resultado es %f\n", resultado);
	return 0;
}

//Los siguienes comandos permiten el uso de la libreria math.h
//gcc -c main.c -lm
//gcc -c funciones.c -lm
//gcc -o ej1 main.o funciones.o -lm