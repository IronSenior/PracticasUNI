#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, ndiv=0;
	cout<<"Introduzca un numero"<<endl;
	cin>>n;
	for (int c=1; c<=sqrt(n); c++){
		if (n%c==0){
			ndiv+=1;
		}
	}
	if (ndiv>=2){
		cout<<"No es primo"<<endl;
	}
	else{
		cout<<"Es primo"<<endl;
	}
    system("pause");
}

