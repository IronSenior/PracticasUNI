#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, i=0, a=0, b=-1; unsigned int c=1 ;
	cout<<"Introduzaca n"<<endl;
	cin>>n;

	while(i<n){
		a = b;
		b = c;
		c = a + b;
		cout<<c<<endl;
		i++;
	}
	
		

    system("pause");
}

