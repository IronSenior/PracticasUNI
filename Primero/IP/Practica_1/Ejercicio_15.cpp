#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int d;
	cout<<"Introduzca el dia en numero"<<endl;
	cin>>d;
	
		switch (d){
			case 1: {cout<<"Lunes"<<endl;}break;
			case 2: {cout<<"Martes"<<endl;}break;
			case 3: {cout<<"Miercoles"<<endl;}break;
			case 4: {cout<<"Jueves"<<endl;}break;
			case 5: {cout<<"Viernes"<<endl;}break;
			case 6: {cout<<"Sabado"<<endl;}break;
			case 7: {cout<<"Domingo"<<endl;}break;
			default: {cout<<"Error"<<endl;}
		}
	
	

    system("pause");
}

