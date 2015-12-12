#include <stdio.h>

int _strncmp(char *s, char *t, int n);
char *_strncpy(char *s, char *t, int n);
char *_strncat(char *s, char *t, int n);

/*
 * Write versions of library functions strncpy, strncat, and strncmp
 * which operate on at most the first n characters of their
 * argument strings.
 *
 * E.G. strncpy(s, t, n) copies at most n characters of t to s.
*/

int main(int argc, const char * argv[]) {
    char aword[] = "kmp";
    char bword[] = "dfa";
    
    printf("%d\n", _strncmp(aword, bword, 3));
    
    char cword[] = "cute cat";
    char dword[] = "copy me";
    
    printf("%s\n", _strncpy(cword, dword, 4));
    
    char eword[] = "I enjoy ";
    char fword[] = "mentos";
    
    printf("%s\n",  _strncat(eword, fword, 3));
    
    return 0;
}

int _strncmp(char *s, char *t, int n)
{
    while (*s++ == *t++ && n--)
        ;
    
    return (int) (*s-- - *t--);
}

char *_strncpy(char *s, char *t, int n)
{
    char *sp = s;
    
    while ((*s++ = *t++) && n--)
        ;
    
    return sp;
}

char *_strncat(char *s, char *t, int n)
{
    char *sp = s;
    
    while (*++s)
        ;
    
    while ((*s++ = *t++) && --n)
        ;
    
    *s = '\0';
    
    return sp;
}