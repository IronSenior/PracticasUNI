#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

float media(int n){
	float k, total=0;
	for (int c=0; c<n; c++){
		cout<<"Introduzca un numero"<<endl;
		cin>>k;
		total = (total + k);
	}
	total = total/n;
	return total;
}



int main(){
	int v;
	cout<<"Introduzca el numero de valores que quiere introducir"<<endl;
	cin>>v;
	cout<<media(v)<<endl;
	

    system("pause");
}

