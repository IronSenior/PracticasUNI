#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
bool esvocal(char a){
	bool result=false;
	char v[]={'a', 'e', 'i', 'o', 'u'};
	for(int i=0; i<5; i++){
		if(a==v[i]){
			result= true;
		}
	}
	return result;
}


int vocales(string cad){
	int total=0;
	int s= cad.size();
	for (int i=0;i<s; i++){ 	
		if(esvocal(tolower(cad[i]))){
			total++;
		}
	}
	return total;
}


int main(){
	cout<<"Introduzca una frase o palabra"<<endl;
	string cad;
	getline(cin, cad);
	cout<<vocales(cad)<<endl;

    system("pause");
}

