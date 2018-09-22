#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int find(string a, string b){
	int sa = a.size();
	int sb = b.size();
	int prim=-1;
	for (int k=0; k<sa; k++){
		if ((b[0]==a[k])&&(prim==-1)){
			for (int i=0; i<sb; i++){
				if (b[i] == a[k+i]){
					prim =k+1;
				}
			}
		}	
	}

	return prim;
}
int main(){
	string cad, cadb;
	getline(cin, cad);
	getline(cin, cadb);
	cout<<find(cad, cadb)<<endl;
	

    system("pause");
}

