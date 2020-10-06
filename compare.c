#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

size_t naive(uint64_t *bitmap, size_t bitmapsize, uint32_t *out)
{
    size_t pos = 0;
    for (size_t k = 0; k < bitmapsize; ++k) {
        uint64_t bitset = bitmap[k];
        size_t p = k * 64;
        for (int i = 0; i < 64; i++) {
            if ((bitset >> i) & 0x1)
                out[pos++] = p + i;
        }
    }
    return pos;
}

size_t improved(uint64_t *bitmap, size_t bitmapsize, uint32_t *out)
{
    size_t pos = 0;
    uint64_t bitset;
    for (size_t k = 0; k < bitmapsize; ++k) {
        bitset = bitmap[k];
        while (bitset != 0) {
            uint64_t t = bitset & -bitset;
            int r = __builtin_ctzll(bitset);
            out[pos++] = k * 64 + r;
            bitset ^= t;                           
        }
    }
    return pos;
}

int main()
{
    uint64_t bitmap[300], test[3];

    test[0] = 0xffffffffffffffff ;
    test[1] = 0xf0f0f0f0f0f0f0f0 ;
    test[2] = 0x8000000000000000 ;

    uint32_t out[64*10] = {0} ;

    for (int i = 0 ; i < 300 ; i++)
    {
        bitmap[i] = test[2] ; 
    }

    //naive(bitmap, 300, out) ;
    improved(bitmap, 300, out) ;

    return 0 ;
}
