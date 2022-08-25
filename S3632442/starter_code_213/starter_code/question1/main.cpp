
#include "main.h"

int main()
{

    Patient a = Patient("don", 50, 'R');

    std::cout << a.Name << " " << a.DOB << " " << a.ward << std::endl;

    return 0;
}