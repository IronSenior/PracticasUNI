#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	unsigned int n, c=0, t=1;
	cout<<"Introduzca su numero"<<endl;
	cin>>n;
	while (c<n){
		t= t*(n-c);
		c++;
	}
	cout<<"El factorial de "<<n<<" es "<<t<<endl;

    system("pause");
}

