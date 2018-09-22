#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, c=1;
	cout<<"Introduzca el numero"<<endl;
	cin>>n;
	while (c<=n){
		if (c%2==0 || c%3==0){
			cout<<c<<endl;
		}
		c++;
	}

    system("pause");
}

