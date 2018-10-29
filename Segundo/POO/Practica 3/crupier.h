//crupier.h
//cabecera de la clase crupier
#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"
#include <string>

using std::string;



//Clase Crupier (Herencia de Persona)
class Crupier : public Persona{
    private:
        string codigo_;

    public:
        //Constructor
        Crupier(string new_dni, string new_code, string new_name="", string new_lname="", 
        int new_age=0, string new_adress="", string new_location="", string new_province="", 
        string new_country=""):Persona(new_dni, new_name, new_lname, 
        new_age, new_adress, new_location, new_province, 
        new_country){codigo_ = new_code;};
        
        //Modificadores
        void setCodigo(string new_code){codigo_ = new_code;};

        //Observadores
        string getCodigo(){return codigo_;};

};

#endif