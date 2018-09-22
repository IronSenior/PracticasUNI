#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cout<<"Introduzca a"<<endl;
	cin>>a;
	cout<<"Introduzca b"<<endl;
	cin>>b;
	cout<<"Introduzca c"<<endl;
	cin>>c;

	if ((c>a) && (c>b)){
		cout<<"El mayor es "<<c<<endl;
	}
	else{
		if ((a>b) && (a>c)){
			cout<<"El mayor es "<<a<<endl;
		}
		else{
			cout<<"El mayor es "<<b<<endl;
		}	
	
	}

    system("pause");
}

