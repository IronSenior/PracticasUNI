#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
void divisores(int v){
	for (int c=1; c<=v; c++){
		if (v%c==0){
			cout<<c<<endl;
		}
	}
	
}	

int main(){
	int n;
	cout<<"introduzca un numero"<<endl;
	cin>>n;
	divisores(n);

    system("pause");
}

