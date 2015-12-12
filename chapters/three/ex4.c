#include <stdio.h>

void itoa (int n, char s[]);
void reverse(char s[]);
int  strsize(char s[]);

/*
 * Modify itoa() so as that it can handle
 * the largest negative number (E.G. 2^(length-1)
 *
 * Explain why the previous version cannot
 * handle this considering a two's
 * complement number system
*/

int main()
{
    char stuff[12];

    itoa(-2147483648, stuff);

    printf("%s\n", stuff);

    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    unsigned k = (unsigned) n;
    sign = n;


    if (sign < 0)
        k = ~k + 1;

    i = 0;

    do {
        s[i++] = k % 10 + '0';
    } while (k /= 10);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int temp, i, j;

    for (i = 0, j = strsize(s)-2; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int strsize(char s[])
{
    int i = 0;
    while (s[i++] != '\0')
        ;
    return i;
}
