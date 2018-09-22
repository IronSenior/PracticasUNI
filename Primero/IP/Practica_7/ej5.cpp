#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

void replace(string &cad, char a, char b){
	int s =cad.size();
	for (int i=0; i<s; i++){
		if(cad[i]=='a'){
			cad[i]='b';
		}
	}
}
int main(){
	cout<<"Introduzca una frase o palabra"<<endl;
	string cad;
	getline(cin, cad);
	char a, b;
	cout<<"Que letra quiere cambiar?"<<endl;
	cin>>a;
	cout<<"Por cual?"<<endl;
	cin>>b;
	replace(cad, a, b);
	cout<<cad<<endl;

	

    system("pause");
}

