#include <stdio.h>

#define EOL '%'
#define MAXLINE 1000

int get_line(char s[]);
int str_len(char s[]);
void decomment(char s[]);

/* removes all comments from a C program */
int main(int argc, const char * argv[]) {
    char line[MAXLINE];

    while (get_line(line) > 0) {
        decomment(line);
        printf("%s", line);
    }
    return 0;
}


int get_line(char s[])
{
    int i, c;

    for (i = 0; (c = getchar()) != EOL && i < MAXLINE-1 && c != '\n'; ++i)
         s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* decomment: offers a native implementation of removing comments from C code */
void decomment(char line[])
{
    int i, v, q, len = str_len(line);
    _Bool in_s = (4 == 2);

    for (i = 0; i < len; ++i) {
        if (line[i] == '"')         { in_s = !in_s; }
        if (line[i] != '/' || in_s) { continue; }

        if (line[i+1] == '/')
            line[i] = '\0';
        else if (line[i+1] == '*') {
            for (v = 3; line[v+i-1] != '*' && line[v+i] != '/'; ++v)
                ;
            len -= v;
            for (q = i; q < len-1; ++q)
                line[q] = line[v+q+1];
            line[q] = '\0';
        }
    }
}

int str_len(char line[])
{
    int i = 0;

    while (line[++i] != '\0')
        ;
    return i;
}
