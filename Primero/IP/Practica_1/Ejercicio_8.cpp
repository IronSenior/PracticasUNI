#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int x0, y0, x1, y1, dis;
	cout<<"Introduzca la coordenada x del primer punto"<<endl;
	cin>>x0;
	cout<<"Introduzca la coordenada y del primer punto"<<endl;
	cin>>y0;
	cout<<"Introduzca la coordenada x del segundo punto"<<endl;
	cin>>x1;
	cout<<"Introduzca la coordenada y del segundo punto"<<endl;
	cin>>y1;

	dis = sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
	cout<<"La distancia del punto 1 con el punto de 2 es de: "<<dis<<endl;
	

    system("pause");
}

