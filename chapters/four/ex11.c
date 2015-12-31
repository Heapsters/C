/*
 * Modify `getop` so that it doesn't
 * need to use ungetch
 */

#include <stdio.h>
#include <ctype.h>

#define NUMBER 0 /* signals that a number was found */

int getop(char s[]);

int main(int argc, const char * argv[]) {
    char s[] = { ' ', ' ', '5', ' ', '6'};
    getop(s);
    getop(s);
    return 0;
}

int getop(char s[])
{
    static char last = EOF;
    int i, c;
    
    if (last != EOF) {
        c = last;
        last = EOF;
    }
    else
        c = ' ';
    
    while ((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        last = c;
    return NUMBER;
}
