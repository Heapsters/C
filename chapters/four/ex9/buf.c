#include "buf.h"

static char buf[BUFSIZE]; // buffer for unget_ch
static int bufp = 0;             // next free position in buf

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("io: too many characters\n");
    else if (c != EOF)
        buf[bufp++] = c;
}
