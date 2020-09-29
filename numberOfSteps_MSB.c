#include <stdio.h>

int numberOfSteps(int num)
{
    if(num)
    {
        int msb = 0;
        while(num>>msb)   msb++ ;
        return __builtin_popcount(num) + msb - 1 ;
    }
    return 0 ;
}


int main()
{
    printf("%d\n",numberOfSteps(8)) ;

    return 0 ;
}
