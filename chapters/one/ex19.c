#include <stdio.h>

#define EOL     '%'
#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char input[], int size);

/* reverses input character strings using the fuction reverse one line at a time */
int main(int argc, const char * argv[])
{
    char line[MAXLINE];
    int len;

    while ((len = getLine(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}

int getLine(char s[], int lim)
{
    int c = 0, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOL && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char line[], int size)
{
    char temp;
    int f, l;

    f = -1;
    l = size-1;
    while (++f < --l) {
        temp = line[f];
        line[f] = line[l];
        line[l] = temp;
    }
}
