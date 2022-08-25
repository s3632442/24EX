#ifndef S3632442_GAME_H
#define S3632442_GAME_H

#include <iostream>
#include <memory>
#include <string>
#include <regex>
#include <vector>
#include <sstream>
#include <random>

#include "../Model/PatientCodes.h"
#include "../Model/Patient.h"
#include "../Model/Register.h"
#include "../Model/Player.h"
#include "Validation.h"
#include "DataHandler.h"
#include "ScoringSystem.h"

const int MAX_PatientS = 72;
const int ASCII_ALPHABET_OFFSET = 65;
const int ASCII_NUMERIC_OFFSET = 48;
const int handPatientcount = 6;
const int ROW_COUNT = 26;
const int COL_COUNT = 26;
const char SPACE = ' ';
const char DASH = '-';
const char PIPE = '|';
const int MINPLAYERS = 2;

class Game
{
public:
    Game();
    ~Game();
    std::string getRegisterAsString();
    bool newGame();
    bool loadGame();
    Player getCurentPlayer();
    std::vector<std::string> tokeniseInput();
    void selectNumPlayers();
    char getNumToPlay();
    void setNumToPlay(char numToPlay);

private:
    Player *player1;
    Player *player2;
    Player *player3;
    Player *player4;
    Player *currentPlayer;
    Register *board;
    bool *itIsPlayer1s_turn;
    LinkedList *bag;
    Validation *validation;
    ScoringSystem *scoringSystem;
    Patient *tempPatient;
    LinkedList *hand;
    bool nextTurn = true;
    bool continueTurn = true;
    char *numToPlay;
    int nextPlayer = 1;
    int plays = 0;

    std::string *c;
    bool *isChar;
    std::regex *statement;
    bool getCharacter(char);

    void saveGame(std::string *&filename);
    bool play();
    void exit();
    void prompt_invalidInput();
    void fillBagAndShuffle();
    void printHand(Player *&);
    void printScores();
    void printRegister();
    void promptForPatientPlacementInput();
    void printCurrentPlayer(Player *&);
    bool takeTurn(Player *&);
    bool checkEndGameConditions(Player *&);
    void printBagPatientCount();
    std::string getUserInput();
    std::string getUserInput(int index);
    void setupNewPlayers();
    bool validateInput(Validation validation);
    void promptForPlays();
    void promptForPlayInput();
    bool getPlayerSelection(Player *&whoseTurnItIs);
    Player *switchPlayer(Player *&);
};

#endif // S3632442_GAME_H