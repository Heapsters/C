#ifndef lines_h
#define lines_h

#include <stdio.h>
#include <string.h>
#include "alloc.h"

#define MAXLEN 100
#define MAXLINES 5000

int readlines(char *s[], int);
void writelines(char *s[], int);
int _getline(char *s, int);

#endif /* lines_h */
