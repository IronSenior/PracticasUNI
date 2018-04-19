#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

string concatena(string a, string b){
	string final = a+b;
	return final;
}
	
int main(){
	string a;
	string b;
	cout<<"Introduzca una palabra"<<endl;
	getline(cin, a);
	cout<<"Introduzca una palabra"<<endl;
	getline(cin, b);
	cout<<concatena(a, b)<<endl;

    system("pause");
}

