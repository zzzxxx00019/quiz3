#include <stdio.h>

int bitwiseComplement(int N)
{
    if(N==0)    return 1 ;
    return N^(0xffffffff >> __builtin_clz(N))  ;
}

int main()
{
    printf("%d\n",bitwiseComplement(7)) ;
    printf("%d\n",bitwiseComplement(10)) ;
    printf("%d\n",bitwiseComplement(0)) ;

    return 0 ;
}
