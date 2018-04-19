#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	float n1, n2, n3, fin;
	cout<<"Introduzaca la nota de practicas"<<endl;
	cin>>n1;
	cout<<"Introduzca la nota del parcial"<<endl;
	cin>>n2;
	cout<<"Introduzca la nota del examen"<<endl;
	cin>>n3;

	n1 = n1 * 0.25;
	n2 = n2 * 0.25;
	n3 = n3 * 0.5;
	fin = n1 + n2 + n3;

	cout<<"la nota final es: "<<fin<<endl;
	if (fin >= 5){
		cout<<"Enhorabuena"<<endl;
}
	else{
		cout<<"A estudiar"<<endl;
}

    system("pause");
}

