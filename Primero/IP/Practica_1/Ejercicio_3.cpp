#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

	int n, r;
	cout<<"Introduzca un numero"<<endl;
	cin>>n;
	if (n>=0){
		r= sqrt(n);
		cout<<"La raiz cuadrada de "<<n<<" es "<<r<<endl;
}
	else{
	cout<<"Error, no se puede calcular la raiz de un numero negativo"<<endl;

}

    system("pause");
}

