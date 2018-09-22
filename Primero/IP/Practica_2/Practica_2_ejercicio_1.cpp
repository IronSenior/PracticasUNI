#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, c=0, t=0, k;
	cout<<"Introduzca el numero de valores de los cuales quiere calcular la media"<<endl;
	cin>>k;
	while (c<k){
		cout<<"Introduzca un valor"<<endl;
		cin>>n;
		t= t+n;
		c++;
	}
	t = t/k;
	cout<<"La media es "<<t<<endl;
    system("pause");
}

