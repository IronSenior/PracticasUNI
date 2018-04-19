#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool palindromo(string cad){
	bool result = false;
	int s = cad.size();
	string inversa = "";
	for(int i=s-1; i>=0; i--){
		inversa += cad[i];
	}
	if (cad == inversa){
		result = true;
	}
	return result;
} 

int main(){
	string a;
	cout<<"Introduzca una palabra"<<endl;
	getline(cin, a);
	if (palindromo(a)){
		cout<<"Es palindromo"<<endl;
	}
	else{
		cout<<"No es palindromo"<<endl;
	}


    system("pause");
}

