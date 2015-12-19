//
//  Write the program tail, which prints the last n
//  lines of its input. By default, n is 10 but it can be
//  changed by an optional argument for example:
//
//      tail -n lines
//
//  will print that last n lines specified.
//
//  The program should behave rationally no matter
//  how unreasonable the input or the value
//  of n.
//
//  Write the program so it makes the best use
//  of available storage; lines should be stored
//  as in the sorting program of section 5.6,
//  not in a two-dimensional array of fixed size.
//

#include <stdio.h>
#include <stdlib.h>
#include "lines.h"

#define DEFAULT_TAIL 10
#define min(a, b) a < b ? a : b

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES];
    int nlines, print, p, c, tail = 0, tailed = 0, ok = 0;

    print = DEFAULT_TAIL;

    while (--argc > 0 && **(++argv) == '-') {
        while ((c = *++argv[0]))
            switch (c) {
                case 'n':
                    tail = 1;
                    ok = 1;
                    break;
                default:
                    printf("tail: illegal option %c\n", c);
                    argc = 0;
                    tailed = 1;
                    break;
            }
    }

    if (tail) {
        if ((p = atoi(*argv)))
            print = p;
        else {
            printf("tail: only integer values\n");
            argc = 0;
            tailed = 1;
            ok = 0;
        }
    }

    if (argc != 1 || ok == 0) {
        printf("usage: tail -n lines\n");
        tailed = 1;
    }
    else {
        nlines = _readlines(lineptr, MAXLINES);
        if (nlines >= 0)
            print = min(print, nlines);
            _writelines(lineptr + nlines - print, print);
    }

    return tailed;
}
