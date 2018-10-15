//jugador.h
//cabecera

#ifndef JUGADOR_H
#define JUAGDOR_H

#include "persona.h"
#include <string>
#include <list>

using std::string;
using std::list;

struct apuesta{
    int type;
    string value;
    int amount;
};

class Jugador : public Persona{
    private:
        string codigo_;
        int dinero_ = 1000;
        list<apuesta> apuestas_;

    public:
        Jugador(string new_dni, string new_code, string new_name="", string new_lname="", 
        int new_age=0, string new_adress="", string new_location="", string new_province="", 
        string new_country=""):Persona(new_dni, new_name, new_lname, 
        new_age, new_adress, new_location, new_province, 
        new_country){codigo_ = new_code;};

        inline string const getCodigo(){return codigo_;};
        inline int const getDinero(){return dinero_;};
        inline list<apuesta> const getApuestas(){return apuestas_;};

        inline bool setDinero(int new_money){dinero_ = new_money;};
        inline bool setCodigo(int new_code){codigo_ = new_code;};

        bool setApuestas(list<apuesta> new_apuesta);

};

#endif