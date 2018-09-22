#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

char letra_dni(string dni){
	char letras[]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
	string ndni= "";
	for(int i=0; i<8; i++){
		ndni += dni[i];
	}
	int n= stoi(ndni)%23;
	return letras[n];
}

bool es_correcto(string &dni){
	bool result = false;
	int ndig= 0;
	if(dni.size() == 9){
		for(int i=0; i<8; i++){
				if (isdigit(dni[i])){
					ndig++;
				}
		}
		if (ndig==8){
			if(toupper(dni[8]) == letra_dni(dni)){
				dni[8] = toupper(dni[8]);
				result = true;
			}
		}
	}
	return result;
}
					


int main(){	
	string dni;
	cout<<"Introduzca su DNI"<<endl;
	cin>>dni;
	if (es_correcto(dni)){
		cout<<"DNI correcto"<<endl;
	}
	else{
		cout<<"DNI incorrecto"<<endl;
	}
	cout<<dni<<endl;

	
    system("pause");
}

