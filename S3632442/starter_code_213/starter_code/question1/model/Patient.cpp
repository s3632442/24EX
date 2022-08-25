

#include "Patient.h"

Patient::Patient()
{

    ward = Ward();
    
};

Patient::Patient(Ward c, Shape s)
{
    
    ward = Ward(c);
};

Patient::~Patient(){

};
Ward Patient::getWard()
{
    return this->ward;
};

void Patient::printDetails()
{

};
