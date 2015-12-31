#ifndef buf_h
#define buf_h

#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

#endif /* buf_h */
