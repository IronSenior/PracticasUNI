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
	


int main(){
	int n;
	cout<<"Introduzca un numero"<<endl;
	cin>>n;
	if (esprimo(n)){
		cout<<"Primo"<<endl;
	}
	else{
		cout<<"No primo"<<endl;
	}

    system("pause");
}

