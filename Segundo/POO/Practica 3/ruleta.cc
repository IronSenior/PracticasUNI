#include "ruleta.h"
#include <cstdbool>
#include <fstream>
#include <cstdlib>


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

//Escribe en jugadores.txt la lista de jugadores
void Ruleta::escribeJugador() {
    std::ofstream ficheplayers;
    ficheplayers.open("jugadores.txt");

    list<Jugador>::iterator itplayer;
    string linea;

    //Equivalente en python a for itplayer in jugadores_
    for (itplayer = jugadores_.begin(); itplayer != jugadores_.end(); itplayer++){
        linea = itplayer->getDNI + "," + itplayer->getCodigo() + "," + itplayer->getNombre() + "," + itplayer->getApellidos() + "," + 
            itplayer->getDireccion() + "," + itplayer->getLocalidad + "," + itplayer->getPais() + "," + itplayer->getDinero();
        ficheplayers << linea << std::endl;
    }
    ficheplayers.close();
}

//Lee el fichero jugadores.txt y los mete en la lista jugadores_
void Ruleta::leeJugadores() {
    list<Jugador> new_players;
    Jugador new_player("def", "def");
    string value;

    std::ifstream ficheroplayers;
    ficheroplayers.open("jugadores.txt");

    //file.eof() do an extra read when all lines are read
    //getline returns false when there is not any line to read
    while(getline(ficheroplayers, value, ',')) {
        new_player.setDNI(value);
        getline(ficheroplayers, value, ',');
        new_player.setCodigo(value);
        getline(ficheroplayers, value, ',');
        new_player.setNombre(value);
        getline(ficheroplayers, value, ',');
        new_player.setApellido(value);
        getline(ficheroplayers, value, ',');
        new_player.setDireccion(value);
        getline(ficheroplayers, value, ',');
        new_player.setLocalidad(value);
        getline(ficheroplayers, value, ',');
        new_player.setProvincia(value);
        getline(ficheroplayers, value, ',');
        new_player.setPais(value);
        getline(ficheroplayers, value);
        new_player.setDinero(stoi(value));

        new_players.push_back(new_player);
    }
    ficheroplayers.close();
    jugadores_ = new_players;
}

void Ruleta::giraRuleta(){
    srand(time(NULL));
    bola_= rand() % 37;
}

//Suma o quita el dinero a los jugadores en función de su apuesta y el tipo de la misma
void Ruleta::getPremios(){
    list<Jugador>::iterator itplayer;
    

    for (itplayer = jugadores_.begin(); itplayer != jugadores_.end(); itplayer++){
        itplayer->setApuestas();
        list<Apuesta>::iterator itapuesta;
        for (itapuesta = itplayer->getApuestas.begin(); itapuesta != itplayer->getApuestas.end(); itapuesta++){
            if (itapuesta->tipo == 1){
                if(stoi(itapuesta->valor) == bola_){
                    banca_ = banca_ - (35 * itapuesta->cantidad);
                    itplayer->setDinero(itplayer->getDinero + (35 * itapuesta->cantidad));
                }
                else{
                    banca_ = banca_ + itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero - itapuesta->cantidad);
                }
            }
            /*else if (itapuesta->tipo == 2){ //No hemos determinado que color sale
                if ((bola_ == 0) || (itapuesta->valor != ))
            }*/
            else if (bola_ == 0){
                banca_ = banca_ + itapuesta->cantidad;
                itplayer->setDinero(itplayer->getDinero - itapuesta->cantidad);
            }
            
            else if(itapuesta->tipo == 3){
                if((itapuesta->valor == "par")&& (bola_%2==0)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero + itapuesta->cantidad);
                }
                else if((itapuesta->valor == "impar")&& (bola_%2!=0)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero + itapuesta->cantidad);
                }
                else {
                    banca_ = banca_ + itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero - itapuesta->cantidad);
                }
            }
            else if(itapuesta->tipo == 4){
                if((itapuesta->valor == "alto") && (bola_>18)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero + itapuesta->cantidad);
                }
                else if((itapuesta->valor == "bajo")&&(bola_<18)){
                    banca_ = banca_ - itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero + itapuesta->cantidad);
                }
                else {
                    banca_ = banca_ + itapuesta->cantidad;
                    itplayer->setDinero(itplayer->getDinero - itapuesta->cantidad);
                }
            }
            
        }

    }
}