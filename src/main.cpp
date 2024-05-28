#include <iostream>
#include "../include/Game/test.h"

int main()
{
    Test* mytest = new Test();

    std::cout << "Hello World!" << std::endl;
    std::cout << mytest->getTest2Var() << std::endl;
}
