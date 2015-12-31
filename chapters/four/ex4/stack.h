/*
 *  Add commands to print the top element of the stack
 *  without popping, to duplicate it, to swap
 *  the top two elements, and add a command to
 *  clear the stack.
 */

#ifndef stack_h
#define stack_h

#include <stdio.h>

#define MAXVAL 100

void push(double f);
double pop(void);
void print_top(void);
void clone(double *to);
void swap_top_two(void);
void clr(void);

#endif /* stack_h */
