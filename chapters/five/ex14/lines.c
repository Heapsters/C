#include "lines.h"

int readlines(char *s[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 1)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return 0;
        else {
            *(line + len - 1) = '\0'; /* deletes newline */
            strcpy(p, line);
            *(s + nlines) = p;
            nlines++;
        }

    return nlines;
}

void writelines(char *s[], int nlines)
{
    while (nlines--)
        printf("%s\n", *s++);
}

int _getline(char *s, int lim)
{
    int c = 0, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        *(s + i) = c;

    if (c == '\n') {
        *(s + i) = c;
        ++i;
    }

    *(s + i) = '\0';

    return i;
}
