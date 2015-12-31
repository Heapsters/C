#include <stdio.h>
#include "buf.h"

int main(void)
{
    ungetch('q');
    ungetch(EOF);
    printf("%c\n", getch());
}
