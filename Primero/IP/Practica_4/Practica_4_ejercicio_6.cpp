#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool esprimo(int v){
	int  ndiv=0;
	bool r=true;
	for (int c=1; c<=v; c++){
		if (v%c==0){
			ndiv++;
		}
	}
	if (ndiv>2){
		r=false;
	}
	return r;
}

void primo(int n){
	int z=0; //Numero de primos calculados
	for (int k=1; z<=n;k++ ){
		if(esprimo(k)){
			cout<<k<<endl;
			z++;
		}
	}
	
}

int main(){
	int t;
	cout<<"Introduzca el numero de primos al que quiere llegar"<<endl;
	cin>>t;
	primo(t);

    system("pause");
}

