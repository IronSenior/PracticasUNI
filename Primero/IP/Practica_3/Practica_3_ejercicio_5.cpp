#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Introduzca un numero"<<endl;
	cin>>n;
	for (int c=1; c<=n; c++){
		if (n%c==0){
			cout<<c<<endl;
		}
	}

    system("pause");
}

