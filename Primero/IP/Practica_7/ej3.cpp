#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

void convierte_a_mayuscula(string& cad){
	int s=cad.size();
	for(int i=0; i<s; i++){
		cad[i]=toupper(cad[i]);
	}

}


int main(){
	string cad;
	cout<<"Introduzca una frase"<<endl;
	getline(cin, cad);
	convierte_a_mayuscula(cad);
	cout<<cad<<endl;

    system("pause");
}

