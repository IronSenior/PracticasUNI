#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int p; 
	cout<<"Introduzca el dinero"<<endl;
	cin>>p;
	cout<<p<<" euros se cambian en: ";

	int b = p/500;
	p = p%500;
	if (b>=1) { 

		if(b==1){cout<<b<<" billete de 500";}  //Comprueba si es uno o mas billetes para sacar por consola billete o billetes

		else{cout<<b<<" billetes de 500";}

		if (p>1) { cout<<", ";} //Comprueba si se sigue o no para poner una coma o no

	}


//Lo demas es todo igual pero cambiando la cantidad por la que se multiplica
	b = p/200;
	p = p%200;
	if (b>=1) {

		if(b==1){cout<<b<<" billete de 200";}

		else{cout<<b<<" billetes de 200";}

		if (p>1) { cout<<", ";}

	}

	b = p/100;
	p = p%100;
	if (b>=1) {

		if(b==1){cout<<b<<" billete de 100";}

		else{cout<<b<<" billetes de 100";}

		if (p>1) { cout<<", ";}

	}
	b = p/50;
	p = p%50;
	if (b>=1) {

		if(b==1){cout<<b<<" billete de 50";}

		else{cout<<b<<" billetes de 50";}

		if (p>1) { cout<<", ";}

	}
	b = p/20;
	p = p%20;
	if (b>=1) {

		if(b==1){cout<<b<<" billete de 20";}

		else{cout<<b<<" billetes de 20";}

		if (p>1) { cout<<", ";}

	}
	b = p/10;
	p = p%10;
	if (b>=1) {

		if(b==1){cout<<b<<" billete de 10";}

		else{cout<<b<<" billetes de 10";}

		if (p>1) { cout<<", ";}

	}
 	b = p/5;
	p = p%5;
	if (b>=1) {

		if(b==1){cout<<b<<" billete de 5";}

		else{cout<<b<<" billetes de 5";}

		if (p>1) { cout<<", ";}

	}
	cout<<endl;



    system("pause");
}

