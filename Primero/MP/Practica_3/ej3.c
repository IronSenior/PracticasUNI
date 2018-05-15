#include <stdio.h>
#include <stdlib.h>

//Calcula la división
void division(int *dividendo, int divisor, int *cociente){
	if (divisor == 0){
		printf("No se puede dividir entre 0\n");
		exit(-1);
	}
	else if (divisor <= *dividendo){
		*dividendo -= divisor;
		*cociente += 1;
		return division(dividendo, divisor, cociente);
	}
}

//Pide dos numeros a los que le calcula la division
int main(int argc, char const *argv[])
{
	int dividendo, divisor, cociente = 0;
	printf("Introduzca el dividendo\n");
	scanf("%i", &dividendo);
	printf("Introduzca el divisor\n");
	scanf("%i", &divisor);
	division(&dividendo, divisor, &cociente);
	printf("El resultado es %i, con resto %i\n", cociente, dividendo);


	return 0;
}