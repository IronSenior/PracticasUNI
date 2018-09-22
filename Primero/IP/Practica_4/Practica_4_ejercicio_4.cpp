#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int factorial(int v){
	int t=1;
	for (int c=1; c<=v;c++){
		t = t*c;
	}
	return t;
}


int main(){
	int n;
	cout<<"Introduzca un numero"<<endl;
	cin>>n;
	cout<<"El factorial de "<<n<<" es "<<factorial(n)<<endl;

    system("pause");
}

