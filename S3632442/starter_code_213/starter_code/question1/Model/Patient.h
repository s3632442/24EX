#ifndef S3632442_Patient_H
#define S3632442_Patient_H

//#include "LinkedList.h"
#include "WardCodes.h"
#include <iostream>
#include <string>
#include <fstream>

// Define a Ward type
typedef char Ward;

class Patient
{
public:
    Patient();
    Patient(std::string Name, int DOB, Ward c, int regNo);
    ~Patient();
    Ward getWard();
    void printWardAndShape();
    Ward ward;
    std::string Name;
    int DOB;
    int regNo;

private:
};

#endif // S3632442_Patient_H