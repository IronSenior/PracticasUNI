#include "DominoOnlineMatch.h"

#include "HubServer.h"

#include <sys/socket.h>
#include <future>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <regex>
#include <sys/types.h>

#define BUFFER_SIZE 250

int DominoOnlineMatch::StartMatch(){
    this->SendMessageToBothPlayers("+Ok. Empieza la partida");

    char buffer[BUFFER_SIZE];
    this->DealTokens();
    this->PutFirstToken();

    while (! this->mIsMatchFinished) {
        this->SendMessageToBothPlayers("TABLERO: " + this->mBoard.GetPrintableBoard());
        this->SendHandToPlayers();
        this->RecreateFDSet();
    
        pselect(FD_SETSIZE, &this->mReadSet, NULL, NULL, NULL, NULL);
        
        if (FD_ISSET(this->mPlayerTurnSocketDescriptor, &this->mReadSet)) {
            if ((recv(this->mPlayerTurnSocketDescriptor, &buffer, BUFFER_SIZE, 0) > 0)){
                this->HandleMessage(buffer);
            } 
        }
    }
    
    return 1;
}


void DominoOnlineMatch::SendMessageToBothPlayers(std::string message){
    for (auto Player = this->mPlayers.begin(); Player != this->mPlayers.end(); Player++){
        send(Player->GetSocketDescriptor(), message.c_str(), BUFFER_SIZE, 0);
    }
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
    this->mPlayerTurnSocketDescriptor = this->mPlayers[firstPlayerIndex].GetSocketDescriptor();
    send(this->mPlayerTurnSocketDescriptor, "+Ok. Has Empezado", BUFFER_SIZE, 0);
    this->mPlayers[firstPlayerIndex].QuitToken(firstToken);
    this->PassTurn();
}


void DominoOnlineMatch::PassTurn(){
    send(this->mPlayerTurnSocketDescriptor, "+Ok. Turno del otro jugador", BUFFER_SIZE, 0);
    if(this->mPlayerTurnIndex == 0){
        this->mPlayerTurnIndex = 1;
    }
    else{
        this->mPlayerTurnIndex = 0;
    }
    this->mPlayerTurnSocketDescriptor = this->mPlayers[this->mPlayerTurnIndex].GetSocketDescriptor();
    send(this->mPlayerTurnSocketDescriptor, "+Ok. Turno de partida", BUFFER_SIZE, 0);
}


void DominoOnlineMatch::SendHandToPlayers(){
    for (auto Player = this->mPlayers.begin(); Player != this->mPlayers.end(); Player++){
        send(Player->GetSocketDescriptor(), ("FICHAS: " + Player->GetPrintableHand()).c_str(), BUFFER_SIZE, 0);
    }
}


void DominoOnlineMatch::RecreateFDSet(){
    FD_ZERO(&this->mReadSet);
    FD_SET(this->mSocketDescriptor, &this->mReadSet);
    FD_SET(this->mPlayerTurnSocketDescriptor, &this->mReadSet);
}


void DominoOnlineMatch::HandleMessage(char * message){
    std::cout<<"From "<<this->mPlayerTurnSocketDescriptor<<" Recieved: "<<message<<std::endl;

    if (std::regex_match(message, std::regex("COLOCAR-FICHA \\|[0-6]\\|[0-6]\\|,(derecha|izquierda)"))){

        std::cmatch RegexMatches;
        std::regex_search(message, RegexMatches, std::regex("\\|([0-6])\\|([0-6])\\|,(derecha|izquierda)"));

        //RegexMatches.str(n) returns the n regex save group () starting at 1
        DominoToken token(atoi(RegexMatches.str(1).c_str()), atoi(RegexMatches.str(2).c_str()));

        this->PutTokenInBoard(token, RegexMatches.str(3).c_str());
    }
    else if (strcmp(message, "ROBAR-FICHA") == 0){
        this->GetTokenFromDomino();
    }
    else if (strcmp(message, "PASO-TURNO") == 0){
        if(this->mBoard.CanPlayerPutToken(this->mPlayers[this->mPlayerTurnIndex]) || (this->mDomino.GetNumberOfFreeTokens() > 0)){
            send(this->mPlayerTurnSocketDescriptor, "Err. Tienes acciones disponibles", BUFFER_SIZE, 0);
        }
        else{
            this->PassTurn();
            if(this->mBoard.CanPlayerPutToken(this->mPlayers[this->mPlayerTurnIndex])){
                this->EndMatch();
            }
        }
    }
    else if(strcmp(message, "SALIR") == 0){
        this->EndMatch();
    }
    else{
        send(this->mPlayerTurnSocketDescriptor, "Err, Bad Message", BUFFER_SIZE, 0);
    }
}


void DominoOnlineMatch::PutTokenInBoard(DominoToken token, const char * position){
    if (this->mPlayers[this->mPlayerTurnIndex].HasToken(token)){
        if (strcmp(position, "derecha") == 0){
            if (this->mBoard.PutTokenOnRight(token)){
                this->mPlayers[this->mPlayerTurnIndex].QuitToken(token);
                if(this->mPlayers[this->mPlayerTurnIndex].GetNumberOfTokens() == 0){
                    this->EndMatch();
                }
                this->PassTurn();
            }
            else{
                send(this->mPlayerTurnSocketDescriptor, "Err. No puedes poner ahí", BUFFER_SIZE, 0);
            }
        }
        else{
            if (this->mBoard.PutTokenOnLeft(token)){
                this->mPlayers[this->mPlayerTurnIndex].QuitToken(token);
                this->PassTurn();
            }
            else{
                send(this->mPlayerTurnSocketDescriptor, "Err. No puedes poner ahí", BUFFER_SIZE, 0);
            }
        }
    }
    else{
        send(this->mPlayerTurnSocketDescriptor, "Err. No tienes esa ficha", BUFFER_SIZE, 0);
    }
}


void DominoOnlineMatch::GetTokenFromDomino(){
    if( ! this->mBoard.CanPlayerPutToken(this->mPlayers[this->mPlayerTurnIndex])){
        if (this->mDomino.GetNumberOfFreeTokens() > 0){
            DominoToken token = this->mDomino.GetRandomFreeDominoToken();
            send(this->mPlayerTurnSocketDescriptor, ("FICHA: " + token.GetPrintableToken()).c_str(), BUFFER_SIZE, 0);
            this->mPlayers[this->mPlayerTurnIndex].RecieveToken(token);
        }
        else{
            send(this->mPlayerTurnSocketDescriptor, "Err. No quedan fichas para robar", BUFFER_SIZE, 0);
            this->PassTurn();
        }
    }
    else{
        send(this->mPlayerTurnSocketDescriptor, "Err. No es necesario robar", BUFFER_SIZE, 0);
    }
}


void DominoOnlineMatch::EndMatch(){
    this->SendMessageToBothPlayers("La Partida terminó");

    std::vector<int> ClientsToAdd = {this->mPlayers[0].GetSocketDescriptor(), this->mPlayers[1].GetSocketDescriptor()};
    HubServer::AddClients(ClientsToAdd);
    this->mIsMatchFinished = true;
}

