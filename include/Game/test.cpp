#include "test.h"

Test::Test()
{}

Test::~Test()
{}

int Test::getVar()
{
    return var;
}

int Test::getTest2Var()
{
    return this->mytest2.getVar();
}