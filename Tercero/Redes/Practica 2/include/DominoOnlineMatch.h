#ifndef DOMINOONLINEMATCH_H
#define DOMINOONLINEMATCH_H

#include <vector>
#include <string>
#include "Domino.h"
#include "DominoPlayer.h"
#include "DominoBoard.h"


class DominoOnlineMatch{
    private:
        int mSocketDescriptor;
        std::vector<DominoPlayer> mPlayers;
        Domino mDomino;
        DominoBoard mBoard;

        int mPlayerTurnIndex;
        int mPlayerTurnSocketDescriptor;
        bool mIsMatchFinished;

        fd_set mReadSet;

    public:
        DominoOnlineMatch(int socketDescriptor, std::vector<int> matchPlayer){
            this->mSocketDescriptor = socketDescriptor;
            for (auto Player = matchPlayer.begin(); Player != matchPlayer.end(); Player++){
                this->mPlayers.push_back(*new DominoPlayer(*Player));
            }

            this->mIsMatchFinished = false;
        };

        int StartMatch();

        void DealTokens();

        void PutFirstToken();

        void SetStartPlayer(int firstPlayerIndex, DominoToken firstToken);

        void SendMessageToBothPlayers(std::string message);

        void PassTurn();

        void RecreateFDSet();

        void HandleMessage(char * message);


};

#endif