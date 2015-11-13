//
//  main.c
//  ex17
//
//  Created by Richard Protasov on 11/12/15.
//  Copyright © 2015 Richard Protasov. All rights reserved.
//

#include <stdio.h>

#define MAXLINE 1000
#define EOL     '%'

int get_line(char line[], int maxLine);
void copy(char to[], char from[]);

/* prints all the input lines which are greater than 80 */

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    
    c = 0;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOL && c!='\n'; ++i)
        
}
