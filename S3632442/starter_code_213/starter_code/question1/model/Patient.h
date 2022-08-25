#ifndef ASSIGN2_PATIENT_H
#define ASSIGN2_PATIENT_H

#include "WardCodes.h"
#include "linkedcdList.h"
#include <iostream>

// Define a Patient type
typedef char Ward;

class Patient
{
public:
    Patient();
    Patient(std::string Name, std::string DOB, std::string Reg, LinkedList admissionHistory);
    ~Patient();
    Patient getPatient();
    void printDetails();

private:
    Ward ward;
};

#endif // ASSIGN2_PATIENT_H