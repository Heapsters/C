#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void un_getch(int);
double getfloat(double *pn);

int main(int argc, const char * argv[]) {
    double some_val = 0.0;
    
    getfloat(&some_val);
    
    printf("%.3f\n", some_val);
    
    return 0;
}

double getfloat(double *pn)
{
    double c, power;
    int sign;
    
    while (isspace(c = getch())) /* skips white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        un_getch(c);
        return 0.0;
    }
    
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    if (c != EOF) {
        un_getch(c);
    }
    
    *pn /= sign * power;
    
    return *pn;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void un_getch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters!\n");
    else
        buf[bufp++] = c;
}