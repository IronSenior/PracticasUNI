//jugador.h
//cabecera
#ifndef JUGADOR_H
#define JUAGDOR_H

#include "persona.h"
#include <string>
#include <list>

using std::string;
using std::list;

struct Apuesta{
    int tipo;
    string valor;
    int cantidad;
};

class Jugador : public Persona{
    private:
        string codigo_;
        int dinero_;
        list<Apuesta> apuestas_;
        list<Apuesta> ApuestaFile_(string file_name);

    public:
        //Constructor
        Jugador(string new_dni, string new_code, string new_name="", string new_lname="", 
        int new_age=0, string new_adress="", string new_location="", string new_province="", 
        string new_country=""):Persona(new_dni, new_name, new_lname, 
        new_age, new_adress, new_location, new_province, 
        new_country){codigo_ = new_code; dinero_ = 1000;};

        //Modificadores
        inline string const getCodigo(){return codigo_;};
        inline int getDinero() const {return dinero_;};
        inline list<Apuesta> getApuestas() const {return apuestas_;};

        //Observadores
        inline void setDinero(int new_money){dinero_ = new_money;};
        inline void setCodigo(string new_code){codigo_ = new_code;};
        void setApuestas();

};

#endif