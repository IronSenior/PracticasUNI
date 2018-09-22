#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int dia;
	cout<<"Introduzca el numero"<<endl;
	cin>>dia;
	if (dia<1 || dia>7) {
		cout<<"Error, el numero no se encuentra dentro del rango de posibles"<<endl;
	}
	else{
		if (dia<=5){
			cout<<"Es un dia laborable"<<endl;
		}
		else{
			cout<<"Es fin de semana party hard"<<endl;
		}

}


    system("pause");
}

