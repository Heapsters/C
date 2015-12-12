#include <stdio.h>

#define EOL     '%'
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(int argc, const char * argv[]) {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)   /* there was a line */
        printf("Size: %d\n\"%s\"", max, longest);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c = 0, i;

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
