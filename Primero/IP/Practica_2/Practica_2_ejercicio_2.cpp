#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int c=0, d, t=0;
	cout<<"Introduzca n"<<endl;
	cin>>d;
	while (c<d){
		t = t+(d-c);
		c++;
	}
	cout<<"El resultado es "<<t<<endl;
    system("pause");
}

