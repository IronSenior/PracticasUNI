#include <stdio.h>
#include <stdlib.h>

void euclides(int* x, int* y, int* mcd){
	int resto = 0;
	*mcd = *y;
	resto = *x % *y;
	if (resto != 0){
		euclides(y, &resto, mcd);
	}
}

int main(int argc, char const *argv[]){
	int x=0, y=0;
	int mcd = 0;
	printf("Introduce el primer numero\n");
	scanf("%i", &x);
	printf("introduce el segundo numero\n");
	scanf("%i", &y);

	if(x>y){
		euclides(&x, &y, &mcd);
	}
	else{
		euclides(&y, &x, &mcd);
	}
	
	printf("El MCD es %i\n", mcd);
	return 0;
}