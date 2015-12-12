#include <stdio.h>

int strend(char *s, char *t);

/*
 * Write the function strend(s, t), which returns
 * 1 if the string t occurs at the end
 * of the string s, and zero other wise
 */
int main(int argc, const char * argv[])
{
    char str[] = "pattern-end";
    char pat[] = "-end";
    
    printf("Pattern: %s\n", strend(str, pat) ? "yes" : "no");
    
    return 0;
}

int strend(char *s, char *t)
{
    char *sp = s, *tp = t;
    int offset;
    
    while (*sp++)
        ;
    while (*tp++)
        ;
    
    offset = (int) (sp - s) - (int) (tp - t);
    
    s += offset;
    
    while (*s++ == *t++)
        if (*t == '\0') {
            return 1;
        }
    return 0;
}