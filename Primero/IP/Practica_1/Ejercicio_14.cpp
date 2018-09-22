#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int a, b;
	cout<<"Introduzca A"<<endl;
	cin>>a;
	cout<<"Introduzca B"<<endl;
	cin>>b;
	if (a>b){
		int c;
		c = b;
		b = a;
		a = c;
	}
	cout<<"A = "<<a<<endl;
	cout<<"B = "<<b<<endl;
	



    system("pause");
}

