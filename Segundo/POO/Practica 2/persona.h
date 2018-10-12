//persona.h
//Cabecera de la clase persona
#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using std::string;


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

    public:
        //Constructor
        Persona(string new_dni, string new_name="", string new_lname="",
        int new_age=0, string new_adress="", string new_location="", 
        string new_province="", string new_country="");

        //Modifiers
        inline void setDNI(string new_dni){dni_ = new_dni;};
        inline void setNombre(string new_name){nombre_ = new_name;};
        inline void setApellido(string new_lname){apellidos_ = new_lname;};
        bool setEdad(int new_age);
        inline void setDireccion(string new_adress){direccion_ = new_adress;};
        inline void setLocalidad(string new_location){localidad_ = new_location;};
        inline void setProvincia(string new_province){provincia_ = new_province;};
        inline void setPais(string new_country){pais_ = new_country;};

        //Observers
        inline string getDNI(){return dni_;};
        inline string getNombre(){return nombre_;};
        inline string getApellidos(){return apellidos_;};
        string getApellidosyNombre();
        inline int getEdad(){return edad_;};
        inline string getDireccion(){return direccion_;};
        inline string getLocalidad(){return localidad_;};
        inline string getProvincia(){return provincia_;};
        inline string getPais(){return pais_;};

        //Otras funciones
        bool mayor();
};


#endif