#include <cstdio>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void fijaValorAleatorio(int v[], int n, int max){
	srand(time(0));
	max++;
	for (int i=0; i<n; i++){
		int na=rand()%max;
		v[i]= na;
	}
}


int main(){
	int max, v[5];
	cout<<"Introduzca el valor maximo"<<endl;
	cin>>max;
	fijaValorAleatorio(v, 5, max);
	for (int i=0; i<5; i++){
		cout<<v[i]<<endl;
	}
    system("pause");
}

