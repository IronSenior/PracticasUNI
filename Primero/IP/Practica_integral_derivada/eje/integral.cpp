#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std; 


		

double integral(double (*func)(double),double init, double end){ //Lo voy a hacer por una suma de Riemann
	int n= 999999;     //numero de rectangulos (A mas rectangulos mas exacto sera el resultado)
	double dx= (end-init)/n;     //Anchura del rectangulo
	double result=0;    //resultado final
	for (int i=0; i<n; i++){    //Divide el area por debajo de la funcion en muchos rectangulos a los que calculare su area y luego se la sumare al total
		double xi = init+i*dx;  //Calcula donde empieza el rectangulo
		double funval = func(xi);  //Calcula la altura del rectangulo
		double recarea= funval*dx; //Calcula el area del rectangulo
		result += recarea; //suma ese area al total
	}
	return result;
}

//cree aqui su funcion
 
//// 
int test();//indica que la funcion test esta mas abajo
int main(){ 
		test();
		cout<<"Correcto"<<endl;
		system("pause");
		return 0;
}
//funcion de test
double const_f(double x){return x;}

int test(){
	assert(fabs( integral(const_f,0,1)-0.5)<1e-2); 
	assert(fabs( integral(sin,0,1)-0.459656)<1e-2); 
	assert(fabs( integral(cos,0,1)-0.841394)<1e-2); 
	assert(fabs( integral(exp,0,2)-6.3891)<1e-2); 
	assert(fabs( integral(log,1,2)-0.38629)<1e-2);    
	return 0;
}	


