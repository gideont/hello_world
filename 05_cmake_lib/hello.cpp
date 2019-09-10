/***********************************************
*    Copyright (C) Gideon Tsang, 2018-2019     *
*                                              *
* The most basic hello world sample code in C. *
***********************************************/
#include <iostream>
#include "mylib.hpp"

using namespace std;

int main()
{
    cout << "Hello in main.. " << endl;
    foo();
    return 0;
}
