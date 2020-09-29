#include <stdio.h>

int numberOfSteps(int num)
{
    return 31 - __builtin_clz(num|0x1) + __builtin_popcount(num) ;
}

int main()
{
    printf("%d\n",numberOfSteps(0)) ;
}
