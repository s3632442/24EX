#ifndef S3632442_Patient_H
#define S3632442_Patient_H

#include "WardCodes.h"
#include <iostream>
#include <string>


// Define a Ward type
typedef char Ward;

class Patient
{
public:
    Patient();
    Patient(std::string Name, int DOB, Ward c);
    ~Patient();
    Ward getWard();
    void printWardAndShape();
    Ward ward;
    std::string Name;
    int DOB;

private:
};

#endif // S3632442_Patient_H