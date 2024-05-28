#pragma once
#include "test2.h"

class Test
{
    public:
        Test();
        ~Test();
        int getVar();
        int getTest2Var();
    private:
        Test2 mytest2;
        const int var = 77;
};
