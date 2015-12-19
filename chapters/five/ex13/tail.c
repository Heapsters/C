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
    int nlines, print, p, tail = 0, tailed = 0;

    print = DEFAULT_TAIL;

    if (argc > 1 && **(++argv) == '-' && *++argv[0] == 'n') {
        tail = 1;
        argc = 1;
        ++argv;
    }

    if (tail) {
        if ((p = atoi(*argv)))
            print = p;
        else {
            printf("tail: only integer values\n");
            argc = 0;
        }
    }

    if (argc != 1) {
        printf("usage: tail -n lines\n");
        tailed = 1;
    }
    else {
        nlines = ROPreadlines(lineptr, MAXLINES);
        print = min(print, nlines);
        ROPwritelines(lineptr + nlines - print, print);
    }

    return tailed;
}
