#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int espacios(string cad){
	int cuenta=0;
	int s= cad.size();
	for (int i=0; i<s;i++){
		if(cad[i]==' '){ // if(cad[i]==32)
			cuenta++;
		}
	}
	return cuenta;
}
	
int main(){
	string cad;
	cout<<"Introduzca una frase"<<endl;
	getline(cin, cad);
	cout<<espacios(cad)<<endl;
	


    system("pause");
}

