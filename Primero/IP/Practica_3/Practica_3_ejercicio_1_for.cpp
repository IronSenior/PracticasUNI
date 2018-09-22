#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){
	int n ,menor=numeric_limits<int>::max();
	for (int c=0 ; c<5 ; c++){
		cout<<"Introduzca un numero"<<endl;
		cin>>n;
		if (n<menor){
			menor = n;
		}
	}
	cout<<"El menor de los cinco es "<<menor<<endl;
    system("pause");
}

