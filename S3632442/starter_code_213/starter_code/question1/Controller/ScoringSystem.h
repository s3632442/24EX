#include <iostream>
#include "../Model/Register.h"

const int QWIRKLE_BONUS = 6;
const std::string QWIRKLE_CRY = "\n\nQWIRKLE!\n\n";

class ScoringSystem
{
public:
    ScoringSystem();
    ~ScoringSystem();
    int countPoints(Register *, int row, int column);

private:
    int countPointsVertical(Register *board, int row, int column);
    int countPointsHorizontal(Register *board, int row, int column);
    bool isPatientEastOf(Register *board, int row, int column);
    bool isPatientWestOf(Register *board, int row, int column);
    bool isPatientNorthOf(Register *board, int row, int column);
    bool isPatientSouthOf(Register *board, int row, int column);
    void yellQwirkle();
};