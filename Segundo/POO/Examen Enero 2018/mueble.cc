

#include "mueble.h"
#include <string>

Mueble::Mueble(int id, std::string nombre, std::string modelo, std::string fecha, std::string color){
    //Con las comprobaciones correspondientes
    setID(id);
    nombre_ = nombre;
    modelo_ = modelo;
    fecha_ = fecha;
    color_ = color;
}



void Mueble::setID(int id){
    //Si el id proporcionado es menor que 0 este tomara 0 como valor
    if(id < 0){
        id_ = 0;
    }
    else{
        id_ = id;
    }
}


//Comprueba que las cadenas no estan vacias antes de asignarlas
bool Mueble::setNombre(std::string nombre){
    if(nombre == ""){
        return false;
    }
    else{
        nombre_ = nombre;
        return true;
    }
}

//Comprueba que las cadenas no estan vacias antes de asignarlas
bool Mueble::setModelo(std::string modelo){
    if(modelo == ""){
        return false;
    }
    else{
        modelo_ = modelo;
        return true;
    }
}

//Comprueba que las cadenas no estan vacias antes de asignarlas
bool Mueble::setFecha(std::string fecha){
    if(fecha == ""){
        return false;
    }
    else{
        fecha_ = fecha;
        return true;
    }
}

//Comprueba que las cadenas no estan vacias antes de asignarlas
bool Mueble::setColor(std::string color){
    if(color == ""){
        return false;
    }
    else{
        color_ = color;
        return true;
    }
}

//Devuelve los datos concatenados y separados por un guión
std::string Mueble::getDatos(){
    std::string r_value;
    r_value = getNombre() + "-" + getModelo() + "-" + getFecha() + "-" + getColor();
    return r_value;
}