#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std; 

 
//// 
int test();
int main(){ 
		int nerrors=test();
		if (nerrors==0){
			cout<<"Correcto "<<endl;
		}
		else{
			cout<<"Hay "<<nerrors<<" errores en el test"<<endl;
		}
		system("pause");

}

int test(){
	int errors=0;


	//test 1(all positive)
	float vec[6]={1,2,30,4,5,6};
	if(  min(vec,6)!=1 ) errors++;

	//test 2(all negative)
	float vec2[6]={-1,-2,-30,-4,-5,-6};
	if(  min(vec2,6)!=-30 ) errors++;

	//test 3 bigger
	float vec3[11]={-1,-2,-30,-4,-5,-6,1,2,5,6,10};
	if(  min(vec3,11)!=-30 ) errors++;

	return errors;
}	


