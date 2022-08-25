
#include "main.h"

int main()
{

    Patient *a = new Patient("don", 50, 'R', 123456);

    std::cout << a->Name << " " << a->DOB << " " << a->ward << " " << a->regNo << std::endl;

    Register reg = Register();
    Node n = Node(a);
    reg.pReg->addFront(a);

    std::cout << reg.pReg->getNodeByData(*a)->getData()->getWard() << std::endl;

    return 0;
}