#include <stdint.h>
#include <stdio.h>

uint64_t gcd64(uint64_t u, uint64_t v) {
    if (!u || !v) return u | v;
    int shift;

    shift = __builtin_ctz( u|v ) ;
    
    if(shift)
    {
        u >>= shift ;
        v >>= shift ;
    }    

    if (!(u & 1))
        u >>= __builtin_ctz(u) ;
    do {
        if (!(v & 1))
            v >>= __builtin_ctz(v) ;
        
        if (u < v) 
        {
            v -= u;
        }
        else 
        {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);

    return u<<shift;

}

int main()
{
    printf("%ld\n", gcd64(18,9)) ;  

    return 0 ;
}
