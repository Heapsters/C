#include <stdio.h>

int bitcount(unsigned x);

/*
 * Write a faster version of bit count
 * with the understanding of why `x &= (x-1)`
 * deletes the rightmost 1-bit of x in a two's
 * complement system
*/
int main(int argc, const char * argv[])
{
    bitcount(0xfff);

    return 0;
}

/* bitcount:  count 1 bits in x */
int bitcount(unsigned x)
{
    int b = 0;

    while (x &= (x-1)) b++;

    return b;
}
