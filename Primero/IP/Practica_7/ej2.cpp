#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int digitos(string cad){
	int total=0;
	int s=cad.size();
	for (int i=0; i<s; i++){
		if (isdigit(cad[i])){
			total++;
		}
	}
	return total;
}
int main(){
	cout<<"Itroduzca una frase"<<endl;
	string cad;
	getline(cin, cad);
	cout<<digitos(cad)<<endl;
	
    system("pause");
}

