#include "ruleta.h"
#include <cstdbool>
#include <fstream>


Ruleta::Ruleta(Crupier new_crupier){
    crupier_ = new_crupier;
    banca_ = 1000000;
    bola_ = -1;
}

bool Ruleta::setBanca(int new_banca){
    if (new_banca < 0 ){
        return false;
    }
    banca_ = new_banca;
    return true;
}

bool Ruleta::setBola(int new_bola){
    if ((new_bola < 0) || (new_bola > 36)){
        return false;
    }
    bola_ = new_bola;
}

//Agrega un nuevo jugador a la lista si no existe y cre su archivo de apuestas
bool Ruleta::addJugador(Jugador new_player){
    string filename;

    //Comprueba si el jugador existe
    if(player_exist_(new_player)){
        return false;
    }

    //Añade el nuevo jugador
    jugadores_.push_back(new_player);


    filename = new_player.getDNI() + ".txt";
    //Comprueba si el archivo ya existe
    if (std::ifstream(filename)){
        return true;
    }
    std::ofstream(filename);
    return true;

}

//Decuelve true si el jugador ya existe en la ruleta
bool Ruleta::player_exist_(Jugador player){
    //Recorremos una lista de la siguiente forma (IMPORTANTE)
    //Equivalente a "for itplayer in jugadores_:" (python)
    list<Jugador>::iterator itplayer;
    for(itplayer = jugadores_.begin(); itplayer != jugadores_.end(); itplayer++){
        if (itplayer->getDNI() == player.getDNI()){
            return true;
        }
    }
}
//Devuelve el numero de jugadores
int Ruleta::count_players_(){
    list<Jugador>::iterator itplayer;
    int counter;
    for(itplayer = jugadores_.begin(); itplayer != jugadores_.end(); itplayer++){
        counter++;
    }
}

//Devuelve 1 al eliminar un jugador, -1 si no hay jugadores y -2 si no existe ese jugador
int Ruleta::deleteJugador(Jugador player){
    if(jugadores_.empty()){
        return -1;
    }

    if (!player_exist_(player)){
        return -2;
    }
    jugadores_.remove(player);
    return 1;
}