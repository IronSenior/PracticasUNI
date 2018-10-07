//persona.h
//Cabecera de la clase persona
#include <string>

#ifndef PERSONA_H
#define PERSONA_H


class Persona{
    private:
        string dni_;
        string nombre_;
        string apellidos_;
        int edad_;
        string direccion_;
        string localidad_;
        string provincia_;
        string pais_;

    private:
        //Constructor
        Persona(string new_dni, string new_name="", string new_lname="", int new_age=0, string new_adress="", string new_location="", string new_province="", string new_country="");

        //Modifiers
        void setDNI(string new_dni){dni_ = new_dni;};
        void setNombre(string new_name){nombre_ = new_name;};
        void setApellido(string new_lname){apellidos_ = new_lname;};
        bool setEdad(int new_age);
        void setDireccion(string new_adress){direccion_ = new_adress;};
        void setLocalidad(string new_location){localidad_ = new_location;};
        void setProvincia(string new_province){provincia_ = new_province;};
        void setPais(string new_country){pais_ = new_country;};

        //Observers
        string getDNI(){return dni_;};
        string getNombre(){return nombre_;};
        string getApellido(){return apellidos_;};
        string getApellidosyNombre();
        string getEdad(){return edad_;};
        string getDireccion(){return direccion_;};
        string getLocalidad(){return localidad_;};
        string getProvincia(){return provincia_;};
        string getPais(){return pais_;};

        //Otras funciones
        bool mayor(){};
};


#endif