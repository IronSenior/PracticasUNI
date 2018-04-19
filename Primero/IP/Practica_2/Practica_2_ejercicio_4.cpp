#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int c=1, n, t=0;
	cout<<"Introduzca n"<<endl;
	cin>>n;
	while (c<=n){
		t = t+c;
		c+=2;
	}
	cout<<t<<endl;

    system("pause");
}

