#include <stdio.h>


struct monomio{
  int cof, grad;
};

void leerMonimio(struct monomio *mono){
  printf("Introduzca coeficiente de monomio\n");
  scanf("%i", &(*mono).cof);
  printf("Introduzca grado de monomio\n");
  scanf("%i", &(*mono).grad);
}

void imprimirMonomio(struct monomio mono){
  printf("Grado: %i, coeficiente: %i \n", mono.grad, mono.cof);

}

int main(int argc, char const *argv[]) {
  int gpoli;
  printf("Introduzca el grado del polinomio\n");
  scanf("%i", &gpoli);
  struct monomio poli[gpoli];

  for(int i=0; i<gpoli; i++){
    leerMonimio(&poli[i]);
  }
  printf("Se imprime por pantalla el polinomio\n");
  for(int i=0; i<gpoli; i++){
    printf("Monomio numero: %i\n", i );
    imprimirMonomio(poli[i]);
  }
  printf("Fin del polinomio\n");

  return 0;
}
