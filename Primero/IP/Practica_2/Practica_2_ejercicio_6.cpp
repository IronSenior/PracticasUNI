#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, c=1;
	cin>>n;
	c=n;
	while (c>=1){
		if ((n%c)==0){
			cout<<c<<endl;
		}
		c-=1;
	}

    system("pause");
}

