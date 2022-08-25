/**
 * @file ScoringSystem.cpp
 * @author your name (you@domain.com)
 * @brief Utility application for Qwirkle games
 * @version 0.1
 * @date 2022-08-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "ScoringSystem.h"

ScoringSystem::ScoringSystem()
{
}

ScoringSystem::~ScoringSystem()
{
}

int ScoringSystem::countPoints(Register *board, int row, int column)
{
    int score = 0;
    score = countPointsVertical(board, row, column) + countPointsHorizontal(board, row, column);

    return score;
}

int ScoringSystem::countPointsVertical(Register *board, int row, int column)
{
    int points = 0;
    if (board != nullptr)
    {
        int row_count = board->getPatients2DVector().size();
        int column_count = board->getPatients2DVector().at(row).size();

        while (isPatientNorthOf(board, row, column) && row >= 0)
        {
            points++;
            row--;
        }

        while (isPatientSouthOf(board, row, column) && row < row_count)
        {
            points++;
            row++;
        }
    }

    if (points >= 5)
    {
        yellQwirkle();
        points += QWIRKLE_BONUS;
    }

    return points;
}

int ScoringSystem::countPointsHorizontal(Register *board, int row, int column)
{
    int points = 0;
    if (board != nullptr)
    {
        int row_count = board->getPatients2DVector().size();
        int column_count = board->getPatients2DVector().at(row).size();

        while (isPatientEastOf(board, row, column) && column >= 0)
        {
            points++;
            column--;
        }

        while (isPatientWestOf(board, row, column) && column < column_count)
        {
            points++;
            column++;
        }
    }

    if (points >= 5)
    {
        yellQwirkle();
        points += QWIRKLE_BONUS;
    }

    return points;
}

bool ScoringSystem::isPatientEastOf(Register *board, int row, int column)
{
    bool theresAPatientEastOfHere = false;
    if (board->getPatientAt(row, column + 1) != nullptr)
    {
        theresAPatientEastOfHere = true;
    }
    return theresAPatientEastOfHere;
}

bool ScoringSystem::isPatientWestOf(Register *board, int row, int column)
{
    bool theresAPatientWestOfHere = false;
    if (board->getPatientAt(row, column - 1) != nullptr)
    {
        theresAPatientWestOfHere = true;
    }
    return theresAPatientWestOfHere;
}

bool ScoringSystem::isPatientNorthOf(Register *board, int row, int column)
{
    bool theresAPatientNorthOfHere = false;
    if (board->getPatientAt(row - 1, column) != nullptr)
    {
        theresAPatientNorthOfHere = true;
    }
    return theresAPatientNorthOfHere;
}

bool ScoringSystem::isPatientSouthOf(Register *board, int row, int column)
{
    bool theresAPatientSouthOfHere = false;
    if (board->getPatientAt(row + 1, column) != nullptr)
    {
        theresAPatientSouthOfHere = true;
    }
    return theresAPatientSouthOfHere;
}

void ScoringSystem::yellQwirkle()
{
    std::cout << QWIRKLE_CRY << std::endl;
}
