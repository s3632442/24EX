#include "Patient.h"


Patient::Patient()
{

    this->regNo = int();
    this->ward = Ward();
    this->Name = std::string();
    this->DOB = int();
};

Patient::Patient(std::string Name, int DOB, Ward c, int regNo)
{

    this->regNo = regNo;
    this->ward = c;
    this->Name = Name;
    this->DOB = DOB;
};

Patient::~Patient(){

};
Ward Patient::getWard()
{
    return this->ward;
};
void Patient::printWardAndShape()
{

    if (this->ward == 'R')
        std::cout << "ACCUTE";
    else if (this->ward == 'O')
        std::cout << "ORTHO";
    else if (this->ward == 'Y')
        std::cout << "NERO";
    else if (this->ward == 'G')
        std::cout << "OUTPATIENTS";
    else if (this->ward == 'B')
        std::cout << "REHAB";
    else if (this->ward == 'P')
        std::cout << "MATERNAL";
};

void operator<<(std::string *&filename, Patient &obj)
{
    Patient temp;
    std::ofstream outputFile(*filename);
    outputFile << obj.regNo << std::endl;
    outputFile << obj.Name << std::endl;
    outputFile << obj.DOB << std::endl;

    outputFile.close();
}