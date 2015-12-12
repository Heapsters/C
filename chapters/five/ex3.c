#include <stdio.h>

void _strcat(char *s, char *t);

// Write a pointer version of the function strcat
int main(int argc, const char * argv[])
{
    char one[] = "Hello,";
    char two[] = " world!";
    
    _strcat(one, two);
    
    printf("%s\n", one);
    
    return 0;
}

void _strcat(char *s, char *t)
{
    while (*++s)
        ;
    while ((*s++ = *t++))
        ;
}