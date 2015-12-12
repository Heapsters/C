#include <stdio.h>

#define MAXLINE 1000
#define EOL '%'

void squeeze(char s[], char o[]);
int get_line(char s[]);

/*
 * Extend squeeze so that it deletes each
 * character in the main string that matches
 * any character in the substring
*/
int main(int argc, const char * argv[]) {
    char line[MAXLINE];

    while (get_line(line) > 0) {
        squeeze(line, "abc");
        printf("%s", line);
    }
    return 0;
}

int get_line(char line[])
{
    int c, i;

    c = 0; /* hushes compilier warning */

    for (i = 0; i < MAXLINE && (c=getchar()) != EOL && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

void squeeze(char line[], char remove[])
{
    int i, j, r;
    _Bool do_remove = (4 == 2);

    for (i = j = 0; line[i] != '\0'; i++) {
        for (r = 0; remove[r] != '\0'; r++)
            if (line[i] == remove[r]) {
                do_remove = !do_remove;
                break;
            }
        if (!do_remove) { line[j++] = line[i]; }
        else            { do_remove = !do_remove; }
    }
    line[j] = '\0';
}
