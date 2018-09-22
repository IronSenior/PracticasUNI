#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n ,total=0, c=0;
	while (n>0){
		cout<<"Introduzca un numero"<<endl;
		cin>>n;
		if (n>0){
			total = total + n;
			c++;
		}
		else {cout<<"El ultimo numero no se contara"<<endl;}
	}
	total = total/c;
	cout<<"La media es "<<total<<endl;


    system("pause");
}

