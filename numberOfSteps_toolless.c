#include <stdio.h>
#include <stdint.h>


int log2N(int v)
{ 
    int r; // result of log2(v) will go here
    int shift;

    r =     (v > 0xFFFF) << 4; v >>= r;
    shift = (v > 0xFF  ) << 3; v >>= shift; r |= shift;
    shift = (v > 0xF   ) << 2; v >>= shift; r |= shift;
    shift = (v > 0x3   ) << 1; v >>= shift; r |= shift;
                                            r |= (v >> 1);
    return r ;
}

int popcnt_branchless(uint32_t v)
{
    uint32_t n;
    n = (v >> 1) & 0x77777777;
    v -= n;
    n = (n >> 1) & 0x77777777;
    v -= n;
    n = (n >> 1) & 0x77777777;
    v -= n;

    v = (v + (v >> 4)) & 0x0F0F0F0F;
    v *= 0x01010101;

    return v >> 24;
}

int numberOfSteps (int num)
{
    return popcnt_branchless(num) + log2N(num) ;
}


int main()
{
    printf("%d\n",numberOfSteps(0)) ;
    return 0 ;
}
