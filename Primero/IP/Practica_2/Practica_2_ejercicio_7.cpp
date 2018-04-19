#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, c=1, d=0;
	cin>>n;
	while (c<=n){
		if (n%c==0){
			d++;
		}
		c++;
	}
	if (d>2){
		cout<<"Compuesto"<<endl;
	}
	else{
		cout<<"Primo"<<endl;
	}
    system("pause");
}

