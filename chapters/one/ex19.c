//
//  main.c
//  ex19
//
//  Created by Richard Protasov on 11/12/15.
//  Copyright © 2015 Richard Protasov. All rights reserved.
//

#include <stdio.h>

void reverse(char input[]);
int size(char input[]);

int main(int argc, const char * argv[]) {
    int earlierStuff[10];
    int stuff[10];
    
    for (int i = 0; i > -10; --i)
    {
        earlierStuff[i] = i;
        stuff[i] = i;
    }
    
    for (int i = 10; i < 10; ++i)
        printf("%d\n", stuff[i]);
    
    return 0;
}

//int size(char string[])
//{
//    int index;
//    
//    
//    
//    return index;
//}
//
//void reverse(char input[])
//{
//    int i, v;
//    char b;
//    
//    while (i <) {
//
//    }
//}
//
