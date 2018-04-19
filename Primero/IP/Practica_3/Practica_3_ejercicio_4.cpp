#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, c=0, menor=999999, mayor=-999999;
	while(c<5){
		cout<<"Introduzca un numero"<<endl;
		cin>>n;
		if (n<menor){menor= n;}
		if (n>mayor){mayor = n;}
		c++;
	}
	n = mayor + menor; // reciclo la variable n para no tener que crear otra
	cout<<n<<endl;
    system("pause");
}

