#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Alumno{				//Creacion de la estructura alumno
	string dni;
	int edad;
	float nota;
};


char letra_dni(string dni){ 				//Funcion reciclada de otra practica que devuelve la letra del dni
	char letras[]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
	string ndni= "";
	for(int i=0; i<8; i++){
		ndni += dni[i];
	}
	int n= stoi(ndni)%23;
	return letras[n];
}


void anadir_alumno(int &matriculados, Alumno v[]){ //Agrega un alumno
	Alumno alum;
	int opc=0;
	cout<<"Introduzca el DNI del alumno"<<endl;
	cin>>alum.dni;
	if((alum.dni[8]!=letra_dni(alum.dni)) || (alum.dni.size()!=9)){ //Comprueba que el dni introducido es válido
		cout<<"DNI no permitido o incorrecto"<<endl;
		opc=1;	
	}
	if(opc!=1){
		cout<<"Introduzca la edad del alumno"<<endl;
		cin>>alum.edad;
		cout<<"Introduzca la nota del alumno"<<endl;
		cin>>alum.nota;
		v[matriculados]=alum;
		matriculados++;
	}

}


void imprimir_alumno(Alumno v[], int matriculados){ //Imprime los datos de solo un alumno
	string DNI;
	cout<<"Introduzca el DNI"<<endl;
	cin>>DNI;
	for (int i=0; i<matriculados; i++){
		if ( v[i].dni==DNI){
			cout<<"DNI: "<<v[i].dni<<" Edad: "<<v[i].edad<<" Nota: "<<v[i].nota<<endl;
			cout<<""<<endl;
			cout<<"Introduzca cualquier valor para continuar"<<endl;
			cin>>DNI;
		}
	}
}

void imprimir_alumnos(Alumno v[], int matriculados){ //Imprime todos los datos
	int n;
	for (int i=0; i<matriculados; i++){
		cout<<"DNI: "<<v[i].dni<<" Edad: "<<v[i].edad<<" Nota: "<<v[i].nota<<endl;
	}
	cout<<"1- Continuar"<<endl;
	cin>>n;
}

void modificar(Alumno v[], int matriculados){ 				//Modifica los datos de un alumno
	string DNI;
	int a;				 //Variables auxiliares
	int o; 				 //Variables auxiliares
	int opcion;
	cout<<"Introduzca el DNI"<<endl;
	cin>>DNI;
	for (int i=0; i<matriculados; i++){
		if ( v[i].dni==DNI){
			cout<<"DNI: "<<v[i].dni<<" Edad: "<<v[i].edad<<" Nota: "<<v[i].nota<<endl;
			cout<<""<<endl;
			a = i;
		}
	}
	cout<<"Que quiere modificar?"<<endl;				 //Menu para poder elegir que datos se quiere modificar
	cout<<"1- DNI"<<endl;
	cout<<"2- Edad"<<endl;
	cout<<"3- Nota"<<endl;
	cout<<"4- Todo"<<endl;
	cin>>opcion;
	
	switch(opcion){
		case 1: { 
			do {					//Lo pedirá hasta que introduzca uno valido
				cout<<"Introduzca el DNI nuevo"<<endl;
				cin>>DNI;
				if((DNI[8]!=letra_dni(DNI)) || (DNI.size()!=9)){				//Comprueba si es valido el DNI
					cout<<"Error"<<endl;
				}
				else{
					v[a].dni = DNI;
				}
			}while((DNI[8]!=letra_dni(DNI)) || (DNI.size()!=9));
		}

		case 2:{
			cout<<"Introduzca la edad nueva"<<endl;
			cin>>o;
			v[a].edad = o;
		}
		case 3:{
			cout<<"Introduzca la nota nueva"<<endl;
			cin>>o;
			v[a].nota = o;
		}
		case 4:{
			anadir_alumno(a, v);				//Esta vez la funcion es llamada con la variable (a) y no con (matriculados) para que cree el alumno en esa posicion
		}
	}
}
			
void eliminar(Alumno v[], int &matriculados){ 				//Funcion que elimina a un alumno
	string DNI;
	cout<<"Introduzca el DNI"<<endl;
	cin>>DNI;
	int a;
	for (int i=0; i<matriculados; i++){
		if ( v[i].dni==DNI){
			a = i;
		}
	}
	v[a] = v[matriculados];
	v[matriculados].dni = "0";
	v[matriculados].edad =0;
	v[matriculados].nota=0;
	matriculados --;
	
}



//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------MAIN



int main(){
	Alumno v[10];
	int matriculados = 0;
	int opcion_menu=0;
	int opt=1;
	do{
		cout<<""<<endl;
		cout<<"Seleccione una opcion"<<endl;
		cout<<"1. Anadir alumno"<<endl;
		cout<<"2. Imprimir datos alumno"<<endl;
		cout<<"3. Imprimir datos de todos los alumnos"<<endl;
		cout<<"4. Modificar Alumno"<<endl;
		cout<<"5. Eliminar a un alumno"<<endl;
		cout<<"6. Salir"<<endl;
		cin>>opcion_menu;
		cout<<""<<endl;
		

		switch(opcion_menu){
			case 1:{anadir_alumno(matriculados, v);}break;
			case 2:{imprimir_alumno(v, matriculados);}break;
			case 3:{imprimir_alumnos(v, matriculados);}break;
			case 4:{modificar(v, matriculados);}break;
			case 5:{eliminar(v, matriculados);}break;
			case 6:{opt=0;}break;
		};
	}while(opt==1);
		


    system("pause");
}

