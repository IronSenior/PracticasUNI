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

	if ( ((a<c) && (c<b)) || ((b<c) && (c<a)) ) {
		cout<<"C se encuentra entre a y b"<<endl;
	}
	else{
		cout<<"C no se encuentra entre a y b"<<endl;
	}

    system("pause");
}

