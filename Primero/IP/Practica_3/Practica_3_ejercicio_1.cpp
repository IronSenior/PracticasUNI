#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

int main(){
	int n, c=0,menor= numeric_limits<int>::max();
	while (c<5){
		cout<<"Introduzca un numero"<<endl;
		cin>>n;
		if (n<menor){
			menor = n;
		}
		c++;
	}
	cout<<"El menor de los cinco es "<<menor<<endl;
    system("pause");
}

