//
//  Modify the sort program to handle a
//  -r flag, which indicates sorting in
//  reverse order. Be sure that -r works
//  with -n.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lines.h"

char *lineptr[MAXLINES];

void quicksort(void *lineptr[], int min, int max,
           int (*comp)(void *v[], int a, int b));
int anumcmp(void *v[], int a, int b);
int astrcmp(void *v[], int a, int b);
void reversal(char *v[], int len);

int main(int argc, char *argv[])
{
    int nlines, c, reverse = 0, numeric = 0, found = 0;

    while (--argc > 0 && **(++argv) == '-')
        while ((c = *++argv[0]))
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    argc = -1;
                    break;
            }

    if (argc != 0)
        printf("usage: sort -r -n values\n");
    else {
        nlines = readlines(lineptr, MAXLINES);
        quicksort((void **) lineptr, 0, nlines-1,
                  (int (*)(void *v[], int a, int b))(numeric ? anumcmp : astrcmp));
        if (reverse)
            reversal(lineptr, nlines);
        writelines(lineptr, nlines);
    }

    return found;
}

void quicksort(void *v[], int min, int max,
               int (*comp)(void *v[], int a, int b))
{
    int i, j;
    void swap(void *v[], int, int);

    if (min >= max)
        return;
    swap(v, min, (min + max)/2);
    j = min;
    for (i = min+1; i <= max; i++)
        if ((*comp)(v, i, min) < 0)
            swap(v, ++j, i);
    swap(v, min, j);
    quicksort(v, min, j-1, comp);
    quicksort(v, j+1, max, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = *(v + i);
    *(v + i) = *(v + j);
    *(v + j) = temp;
}

void reversal(char *v[], int len)
{
    void *temp;
    int i = -1;

    while (++i < --len) {
        temp = *(v + i);
        *(v + i) = *(v + len);
        *(v + len) = temp;
    }
}

int astrcmp(void *v[], int i, int j)
{
    char *s = *(v + i), *t = *(v + j);

    while (*s++ == *t++)
        ;

    return (int) (*s-- - *t--);
}

int anumcmp(void *v[], int i, int j)
{
    char *s = *(v + i), *t = *(v + j);
    double v1, v2;

    v1 = atof(s);
    v2 = atof(t);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
