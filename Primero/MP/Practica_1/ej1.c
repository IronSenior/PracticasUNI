#include <stdio.h>

/*
Codifica un programa que utilice la sentencia printf para escribir el tamaño
de los tipos de las siguientes variables:

int a, *b, **c;
double d, *e, **f;
char g, *h, **i;

*/

int main(void){
	int a, *b, **c;
  	double d, *e, **f;
  	char g, *h, **i;

	printf("a: %d - *b: %d -**c %d \n", sizeof(a), sizeof(b), sizeof(c));
 	printf("d: %d - *e: %d -**f %d \n", sizeof(d), sizeof(e), sizeof(f));
  	printf("g: %d - *h: %d -**i %d \n", sizeof(g), sizeof(h), sizeof(i));



	return 0;
}
