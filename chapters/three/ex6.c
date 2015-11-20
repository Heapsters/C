//
//  main.c
//  ex6
//
//  Created by Richard Protasov on 11/20/15.
//  Copyright © 2015 Richard Protasov. All rights reserved.
//

#include <stdio.h>

void itoa(int n, char s[], int m);
void reverse(char s[]);
int  strsize(char s[]);

/* 
 * Write a version of itoa() that accepts three arguments 
 * where the third is minumum field width. 
 *
 * The converted number must be padded with blanks on the left 
 * if necessary to make it wide enough
*/
int main()
{
    char ex[12];
    
    itoa(-1024, ex, 8);
    
    printf("%s\n", ex);
    return 0;
}

void itoa(int n, char s[], int min)
{
    int i;
    _Bool neg = (n < 0);
    
    i = 0;
    
    do {
        s[i++] = '0' + (n % 10) * (neg ? -1 : 1);
    } while (n /= 10);
    
    if (neg) {
        s[i++] = '-';
    }
    
    while (i < min) {
        s[i++] = ' ';
    }
    
    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int temp, i, j;
    
    for (i = 0, j = strsize(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int strsize(char s[])
{
    int i = 0;
    
    while (s[++i] != '\0')
        ;
    return i;
}
