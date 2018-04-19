#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){
	int n ,mayor=numeric_limits<int>::min();
	for (;n>0;){
		cout<<"Introduzca un numero"<<endl;
		cin>>n;
		if ((n>mayor) && (n>0)){
			mayor = n;
		}
	}
	cout<<"El mayor de los cinco es "<<mayor<<endl;


    system("pause");
}

