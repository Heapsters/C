//
//  main.c
//  ex17
//
//  Created by Richard Protasov on 11/12/15.
//  Copyright © 2015 Richard Protasov. All rights reserved.
//

#include <stdio.h>

#define MAXLINE 1000
#define MINSIZE 80
#define EOL     '%'

int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

/* prints all the input lines which are greater than 80 */
int main(int argc, const char * argv[]) {
    char line[MAXLINE];
    int len;
    
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > MINSIZE)
            printf("%s", line);
    return 0;
}

/* get_line: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    
    c = 0;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOL && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
