//
//  main.c
//  ex13
//
//  Created by Richard Protasov on 11/11/15.
//  Copyright © 2015 Richard Protasov. All rights reserved.
//

#include <stdio.h>

/* print a histogram of the lengths of words in an input */

int main(int argc, const char * argv[]) {
    int c, i, j, v, nlength, nwords, bins, max, min;
    float interval;
    int words[100], buckets[bins];
    
    nlength = nwords = 0;
    
    bins = 5;
    
    max = 0;
    min = 500;
    
    for (i = 0; i < 50; ++i)
        words[i] = 0;
    for (i = 0; i < 5; i++)
        buckets[i] = 0;
    
    while ((c = getchar()) != '%') {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (nlength > 0) {
                ++words[nlength];
                ++nwords;
                if (nlength > max)      max = nlength;
                else if (nlength < min) min = nlength;
                nlength = 0;
            }
        }
        else
            ++nlength;
    }
    
    interval = (float)(max-min)/bins;
    
    for (i = min; i <= max; ++i) {
        buckets[(int)(i/interval)] += words[i];
    }
    
    
    for (i = 0; i < bins; ++i) {
        for (j = 0; j < buckets[i]; ++j)
            printf("-");
        printf("|\n");
        for (j = 0; j < 2; ++j) {
            for (v = 0; v < buckets[i]; ++v)
                printf(" ");
            printf("|\n");
        }
        for (j = 0; j < buckets[i]; ++j)
            printf("-");
        printf("|\n");
    }
    
    return 0;
}
