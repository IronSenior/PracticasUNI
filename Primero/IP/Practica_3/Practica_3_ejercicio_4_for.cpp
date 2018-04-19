#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, menor=999999, mayor=-999999;
	for(int c=0; c<5; c++){
		cout<<"Introduzca un numero"<<endl;
		cin>>n;
		if (n<menor){menor= n;}
		if (n>mayor){mayor = n;}
	}
	n = mayor + menor; // reciclo la variable n para no tener que crear otra
	cout<<n<<endl;

    system("pause");
}

