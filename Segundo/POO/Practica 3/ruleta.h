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
        bool player_exist_(Jugador player);
        int count_players_();

    private:
        Ruleta(Crupier new_crupier);

        inline int getBola() const {return bola_;};
        inline int getBanca() const {return banca_;};
        inline Crupier getCrupier() const {return crupier_;};
        inline list<Jugador> getJugadores() const {return jugadores_;};

        inline void setCrupier(Crupier new_crupier){crupier_ = new_crupier;};
        bool setBanca(int new_banca);
        bool setBola(int new_bola);

        bool addJugador(Jugador new_player);
        int deleteJugador(Jugador player);
        void escribeJugador() const;
        void leeJugadores();
        void giraRuleta();
        void getPremios();

};

#endif