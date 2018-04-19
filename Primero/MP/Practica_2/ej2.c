#include <stdio.h>
#include <stdlib.h>

void funcion(int v[], int tmn, int num, int men[], int may[]){
	int auxm = 0;
	int auxM = 0;

	for (int i =0; i<tmn; i++){
		if (v[i]>num){
			may[auxM] = v[i];
		}
		else{
			men[auxm] = v[i];
		}
	}
}


int main(int argc, char const *argv[]){
	int v[11];
	int men[5];
	int may[5];
	int num;
	for(int i=0; i<11; i++){
		printf("Introduce un valor\n");
		scanf("%i", &v[i]);
	}
	printf("Ahora introduce el valor medio\n");
	scanf("%i", &num);
	funcion(v, 11, num, men, may);
	for(int i=0; i<5; i++){
		printf("Valor delante %i\n", men[i]);
	}
	return 0;
}

