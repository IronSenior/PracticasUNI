//persona.cc
//Defición de los metodos de persona

#include <string>
#include "persona.h"

//Asigna los valores predeterminados al crear la instancia
Persona::Persona(string new_dni, string new_name="", string new_lname="", int new_age=0, string new_adress="", string new_location="", string new_province="", string new_country=""){
    dni_= new_dni;
    nombre_ = new_name;
    apellidos_ = new_lname;
    edad_ = new_age;
    direccion_ = new_adress;
    localidad_ = new_location;
    provincia_ = new_province;
    pais_ = new_country;
}

//Comprueba que la edad es un numero positivo y lo asigna a edad_
bool Persona::setEdad(int new_age){
    if (new_age > 0){
        edad_ = new_age;
        return true;
    }
    else{
        return false;
    }
}

//Devuelve uan cadena formada por el apellido y el nombre separados por una coma
string Persona::getApellidosyNombre(){
    string name_lname;
    name_lname = apellidos_ + ", " + nombre_;
}

//DEvuelve True si la persona es mayor de edad
bool Persona::mayor(){
    if (edad_ < 18){
        return false;
    }
    else{
        return true;
    }
}