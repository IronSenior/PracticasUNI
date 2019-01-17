#include "mesa.h"
#include <string>


bool Mesa::setMaterial(std::string material){
    if(material == ""){
        return false;
    }
    else{
        material_ = material;
        return true;
    }
}

//Comprueba que todos los datos por defecto han sido modificados (Devuelve false en caso contrario)
bool Mesa::checkEstado(){
    if((getId() == 0)||(getPatas == 0)){
        return false;
    }
    else if ((getNombre()=="NO_ASIGNADO")||(getModelo()=="NO_ASIGNADO")||(getFecha()=="NO_ASIGNADO")||
             (getColor()=="NO_ASIGNADO")||(getMaterial()=="NO_ASIGNADO")){
        return false;
    }
    else{
        return true;
    }
}

