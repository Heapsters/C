#include <stdio.h>
#include <string.h>
#include "alloc.h"
#include "lines.h"

int _readlines(char *s[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 1)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return 0;
        else {
            *(line + len - 1) = '\0'; /* delete newline */
            strcpy(p, line);
            *(s + nlines) = p;
            nlines++;
        }

    return nlines;
}

void _writelines(char *lineptr[], int nlines)
{
    int i;

    i = 0;
    while (nlines--)
        printf("%s\n", *lineptr++);
}

int _getline(char *s, int lim)
{
    int c, i;

    c = 0; /* silences compiler warnings */

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        *(s + i) = c;

    if (c == '\n') {
        *(s + i) = c;
        ++i;
    }

    *(s + i) = '\0';

    return i;
}
