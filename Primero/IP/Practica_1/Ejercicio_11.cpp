#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int m;
	cout<<"Introduzca el mes"<<endl;
	cin>>m;
	
	if ((m>=1) && (m<= 12)){ 
		if (m==2){
			cout<<"28 dias tiene tu mes"<<endl;
		}
		else {
			if (m<7){
				if(m%2==0){
					cout<<"30 dias tiene tu mes"<<endl;
				}
				else {
					cout<<"31 dias tiene tu mes"<<endl;
				}

			}
			else{
				if(m%2==0){
					cout<<"31 dias tiene tu mes"<<endl;
				}
				else {
					cout<<"30 dias tiene tu mes"<<endl;
				}
			}
		}
	}
	else {
		cout<<"No existe el mes "<<m<<endl;
	}	
    system("pause");
}

