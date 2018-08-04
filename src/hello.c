#include <stdio.h>
#include "foo.h"
 
int main(void)
{
    puts("Hello! This is a shared library test!\n");
    foo();
    return 0;
}
