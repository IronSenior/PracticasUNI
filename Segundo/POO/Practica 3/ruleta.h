//ruleta.h
//cabecera de la clase ruleta
#ifndef RULETA_H
#define RULETA_H

#include "jugador.h"
#include "crupier.h"
#include <cstdbool>
#include <cstdlib>

using std::list;

class Ruleta{
    private:
        int banca_;
        int bola_;
        Crupier crupier_;
        list<Jugador> jugadores_;
    private:
        Ruleta(Crupier new_crupier);

        inline int getBola() const {return bola_;};
        inline int getBanca() const {return banca_;};
        inline Crupier getCrupier() const {return crupier_;};
        inline list<Jugador> getJugadores() const {return jugadores_;};

        inline void setCrupier(Crupier new_crupier){crupier_ = new_crupier;};
        bool setBanca(int new_banca);
        bool setBola(int new_bola);
};

#endif