#include <iostream>
using namespace std;

void lee(float v[], int n){
	int a;
	for (int i=0; i<n; i++){
		cout<<"Introduca un valor"<<endl;
		cin>>a;
		v[i] = a;						
	}
}

void imprime(float v[], int n){
	for (int i=0; i<n; i++){
		cout<<v[i]<<endl;
	}
}

int main(){
	float v[5];
	lee(v, 5);
	imprime(v, 5);
	int n;
	cin>>n;
}