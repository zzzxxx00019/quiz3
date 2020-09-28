#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfFour(int num)
{
    return __builtin_popcount(num) == 1 && ( __builtin_ctz(num)%2) == 0 ;
}

bool PowerOfFour(int num)
{
    return num > 0 && (num & (num - 1))==0 &&
           !(__builtin_ctz(num) & 0x1);
}

int main()
{
    for(int i=1 ; i<100000 ; i+=1)
    {
        if( isPowerOfFour(i) !=  PowerOfFour(i))  printf("%d Error!!\n",i) ;
    }

    printf("ending!\n") ;

    return 0 ;
}
