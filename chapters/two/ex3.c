#include <stdio.h>

#define EOL '%'
#define MAXLINE 1000

long unsigned htoi(char s[]);
int getnewline(char s[]);
int str_length(char s[]);
long unsigned power(int b, int p);

/*
 * Write the function htoi(s) which converts a string
 * of hexadecimal digits into integer values
*/
int main(int argc, const char * argv[])
{
    char line[MAXLINE];

    while (getnewline(line) > 0)
        printf("%lu\n", htoi(line));

    return 0;
}

int getnewline(char line[])
{
    int c, i;

    c = 0; /* hushes compilier warning */

    for (i = 0; i < MAXLINE && (c=getchar())!=EOL && c!='\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return  i;
}

long unsigned htoi(char hexes[])
{
    int i, v, c, len = str_length(hexes);
    long unsigned h;
    h = v = 0;

    for (i = 0; i < len-1; i++) {
        c = hexes[i];
        if      (c >= '0' && c <= '9') { v = c - '0'; }
        else if (c >= 'a' && c <= 'f') { v = 10 + (c - 'a'); }
        h += power(16, len - (i + 2)) * v;
    }

    return h;
}

int str_length(char line[])
{
    int i = 0;

    while (line[++i] != '\0')
        ;

    return i;
}

long unsigned power(int base, int p)
{
    int i;
    long unsigned result = 1;

    for (i = 0; i < p; ++i)
        result *= base;

    return result;
}
