#ifndef S3632442_VALIDATION_H
#define S3632442_VALIDATION_H
#include "../Model/Patient.h"
#include "../Model/LinkedList.h"
#include "../Model/Register.h"

class Validation
{

public:
    Validation();
    ~Validation();

    bool setInput();
    void getInput();
    // test in game.cpp newGame();
    bool validateInputLength(int);
    // called from checkEmptySpace()
    bool inputWithinBounds(char, int);
    // test in game.cpp newGame();
    // see if Patient in hand
    bool validatePatientChosen(LinkedList *, Patient *);
    // see if space is empty before trying to validate move by game rules
    bool checkEmptySpace(Patient *, Register *, int, int);
    // test in qwirkle.cpp
    // gets input from user as a string, string is used to make a file object and try to open this file.
    // if file cannot be read then the file doesnt exist and false is returned
    bool checkFileExists(std::string);
    // test in qwirkle.cpp
    // name needs to be uppercase, only letters, no numbers or symbols
    bool playerNameValid(std::string &);
    // validates the user input for a valid board position
    bool validateInputProposed(Patient *, Register *, std::string);
    // validateMove will check surrounding Patients to follow game rules
    bool validateMove(Register *, int, int, bool, Patient *);
    bool validateNorth(Register *, int, int, Patient *);
    bool validateEast(Register *, int, int, Patient *);
    bool validateSouth(Register *, int, int, Patient *);
    bool validateWest(Register *, int, int, Patient *);
    bool checkAdjacentPatientsRowLength(Register *, int, int);

private:
    Patient PatientPlayed;
    char userInput[5];
    bool checkRegisterIsEmpty(Register *boardPointer);
};
#endif // S3632442_VALIDATION_H