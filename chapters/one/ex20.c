//
//  main.c
//  ex20
//
//  Created by Richard Protasov on 11/13/15.
//  Copyright © 2015 Richard Protasov. All rights reserved.
//

#include <stdio.h>

#define EOL      '%'
#define TABWIDTH 4
#define MAXLINE  1000

char line[MAXLINE];
int len;

int getLine(void);
void detab(char line[]);

/* replaces tabs with spaces for each line inputed */

int main(int argc, const char * argv[])
{
    extern char line[];
    extern int len;
    
    while ((len = getLine()) > 0) {
        detab(line);
        printf("%s", line);
    }
    return 0;
}

int getLine(void)
{
    int c = 0, i;
    extern char line[];
    
    for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOL && c != '\n'; ++i)
            line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void detab(char line[])
{
    extern int len;
    
    int i, v, offset;

    i = -1;
    while (++i < len)
    {
        if (line[i] != '\t') { continue; }
        
        offset = TABWIDTH - (i % TABWIDTH) - 1; /* calculates remaining distance to the next tab stop */
        
        /* 
         * Beginining from the end, displaces all characters to the right of
         * the tab by the offset calculated above.
         * 
         * On the second iteration it replaces the the tab with the correct
         * count of spaces.
         */
        
        for (v = len; v > i; --v)
            line[v+offset] = line[v];
        for (v = 0; v < offset+1; ++v)
            line[v+i] = ' ';
        len += offset;
    }
}
