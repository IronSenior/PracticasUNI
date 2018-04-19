#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, c=1;
	cin>>n;
	while (c<=n){
		if (n%c==0){
			cout<<c<<endl;
		}
		c++;
	}

    system("pause");
}

