#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool espar(int v){
	bool r;
	if(v%2==0){	
		r = true;
	}
	else{
		r = false;
	}
	return r;
}




int main(){
	int n;
	cout<<"Introduzca un numero"<<endl;
	cin>>n;
	if (espar(n)){
		cout<<"Par"<<endl;
	}
	else{
		cout<<"Impar"<<endl;
	}

    system("pause");
}

