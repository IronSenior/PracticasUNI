#include "DominoOnlineMatch.h"

#include "HubServer.h"

#include "DominoGame.h"


#include <sys/socket.h>
#include <future>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

#include <sys/types.h>

int DominoOnlineMatch::StartMatch(){
    this->SendMessageToBothPlayers("+Ok. Empieza la partida");

    char buffer[100];
    this->DealTokens();
    this->PutFirstToken();

    while (! this->mIsMatchFinished) {
        this->PassTurn();
        this->RecreateFDSet();
    
        pselect(FD_SETSIZE, &this->mReadSet, NULL, NULL, NULL, NULL);
        
        if (FD_ISSET(this->mPlayerTurnSocketDescriptor, &this->mReadSet)) {
            if ((recv(this->mPlayerTurnSocketDescriptor, &buffer, 100, 0) > 0)){
                this->HandleMessage(buffer);
            } 
        }
    }
    
    return 1;
}


void DominoOnlineMatch::DealTokens(){
    for (int i = 0; i < 7; i++){
        this->mPlayers[0].RecieveToken(this->mDomino.GetRandomFreeDominoToken());
        this->mPlayers[1].RecieveToken(this->mDomino.GetRandomFreeDominoToken());
    }
}


void DominoOnlineMatch::PutFirstToken(){
    DominoToken Player1Token = this->mPlayers[0].GetFirstToken();
    DominoToken Player2Token = this->mPlayers[1].GetFirstToken();


    // Im not proud of this piece of code :(
    if (Player1Token.IsDouble()){
        if (Player1Token > Player2Token){
            this->SetStartPlayer(0, Player1Token);
        }
        else if(Player2Token.IsDouble()) {
            this->SetStartPlayer(1, Player2Token);
        }
    }
    else if (Player2Token.IsDouble()){
        this->SetStartPlayer(1, Player2Token);
    }
    else{
        if (Player1Token > Player2Token){
            this->SetStartPlayer(0, Player1Token);
        }
        else{
            this->SetStartPlayer(1, Player2Token);
        }
    }
}


void DominoOnlineMatch::SetStartPlayer(int firstPlayerIndex, DominoToken firstToken){
    this->mPlayerTurnIndex = firstPlayerIndex;
    this->mBoard.PutFirstToken(firstToken);
    this->mPlayers[firstPlayerIndex].QuitToken(firstToken);
}


void DominoOnlineMatch::PassTurn(){
    send(this->mPlayerTurnSocketDescriptor, "+Ok. Turno del otro jugador", 100, 0);
    if(this->mPlayerTurnIndex == 0){
        this->mPlayerTurnIndex = 1;
    }
    else{
        this->mPlayerTurnIndex = 0;
    }
    this->mPlayerTurnSocketDescriptor = this->mPlayers[this->mPlayerTurnIndex].GetSocketDescriptor();
    send(this->mPlayerTurnSocketDescriptor, "+Ok. Turno de partida", 100, 0);
}


void DominoOnlineMatch::RecreateFDSet(){
    FD_ZERO(&this->mReadSet);
    FD_SET(this->mSocketDescriptor, &this->mReadSet);
    FD_SET(this->mPlayers[this->mPlayerTurnIndex].GetSocketDescriptor(), &this->mReadSet);
}


void DominoOnlineMatch::HandleMessage(char * message){
    char buffer[100];
    std::cout<<"From "<<this->mPlayerTurnSocketDescriptor<<" Recieved: "<<message<<std::endl;

    if (strcmp(message, "hola") == 0){
        std::cout<<"Caracola"<<std::endl;
    }

}


void DominoOnlineMatch::SendMessageToBothPlayers(std::string message){
    for (auto Player = this->mPlayers.begin(); Player != this->mPlayers.end(); Player++){
        send(Player->GetSocketDescriptor(), message.c_str(), 100, 0);
    }
}