#include "stack.h"

static int sp = 0;
static double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_top(void)
{
    if (sp >= 0)
        printf("%g", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

void clone(double *to)
{
    int i;
    for (i = 0; i < sp; i++)
        to[i] = val[i];
}

void swap_top_two(void)
{
    double temp;

    if (sp > 1) {
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }
    else
        printf("error: less than two values\n");
}

void clr(void)
{
    sp = 0;
}
