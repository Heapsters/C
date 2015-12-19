#include <stdio.h>
#include "alloc.h"

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int size)
{
    if (allocbuf + ALLOCSIZE - allocp > size) {
        allocp += size;
        return allocp - size;
    } else
        return 0;
}

void freeit(char *p)
{
    if (p >= allocbuf && p <= allocp)
        allocp = p;
}
