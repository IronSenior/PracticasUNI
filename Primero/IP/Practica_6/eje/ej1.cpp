#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std; 

//cree aqui su funcion
 
int find(float m[4][4], float val){
	int total=0;
	for (int i=0; i<4; i++){
		for (int k=0; k<4; k++){
			if (m[i][k]==val){
				total++;
			}
		}
	}
	return total;

}


//// 
int test();//indica que la funcion test esta mas abajo
int main(){ 
		test();
		cout<<"Correcto"<<endl;
		system("pause");
		return 0;

}
//funcion de test
int test(){
	
	float m[4][4]={ {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
	assert(  find(m,1 )==4);
	assert(  find(m,2 )==4);
	assert(  find(m,-1 )==0);
	return 0;
}	


