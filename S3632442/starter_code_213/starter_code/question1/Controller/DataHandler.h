#ifndef S3632442_DATAHANDLER_H
#define S3632442_DATAHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include "../Model/Register.h"
#include "../Model/Player.h"
#include "../Model/LinkedList.h"

class DataHandler
{
public:
    DataHandler();
    ~DataHandler();
    bool loadData(std::string);
    bool saveData(char *&players);
    void setNumToPlay(char numberOfPlayers);
    void setPlayer1(Player *&player1);
    void setPlayer2(Player *&player2);
    void setPlayer3(Player *&player3);
    void setPlayer4(Player *&player4);
    char getNumToPlayLoaded();
    void setRegister(Register *&board);
    void setBag(LinkedList *&bag);
    void setCurrentPlayerName(std::string *&currentPlayerName);
    void setFilename(std::string *&filename);
    std::string getPlayer1Name();
    std::string getPlayer2Name();
    std::string getPlayer3Name();
    std::string getPlayer4Name();
    void fillBagWithSavedPatients(LinkedList *&bag);
    int getPlayer1Score();
    int getPlayer2Score();
    int getPlayer3Score();
    int getPlayer4Score();
    void fillPlayer2HandWithSavedPatients(LinkedList *&);
    void fillPlayer1HandWithSavedPatients(LinkedList *&);
    void fillPlayer3HandWithSavedPatients(LinkedList *&);
    void fillPlayer4HandWithSavedPatients(LinkedList *&);
    int getRegisterHeight();
    int getRegisterWidth();
    std::string getCurrentPlayerName();
    Register getRegister();

private:
    std::string *gameState;
    std::string *filename;
    std::string *currentPlayerName;
    LinkedList *bag;
    Register *board;
    Player *player1;
    Player *player2;
    Player *player3;
    Player *player4;
    std::string handAsString(Player *&);
    std::string boardShapeAsString(Register *&board);
    std::string setRegisterStateAsString(Register *&board);
    std::string bagContentsAsString(LinkedList *&bag);
    char *numToPlayLoaded;
};

#endif // S3632442_DATAHANDLER_H