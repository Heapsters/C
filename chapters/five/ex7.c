#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXSTORAGE 10000

char *lineptr[MAXLINES];

size_t readlines(char *lineptr[], size_t nlines, char *storage);
void writelines(char *lineptr[], size_t nlines);

void quicksort(char *lineptr[], int min, int max);

/* 
 * Rewrite `readlines` to store lines in 
 * an array supplied by `main`
 * rather than calling `alloc` to maintain 
 * storage.
*/

int main(int argc, const char * argv[])
{
    size_t nlines; /* number of input lines to read */
    char storage[MAXSTORAGE];

    if ((nlines = readlines(lineptr, MAXLINES, storage))) {
        quicksort(lineptr, 0, (int) (nlines - 1));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000

size_t readlines(char *lineptr[], size_t maxlines, char *storage)
{
    size_t max_line, max_storage;
    size_t len, nlines;
    char *p, line[MAXLEN], *lpt;
    char *memory(char *buf, size_t limit, size_t amt);
    
    lpt = line;
    
    max_storage = MAXSTORAGE;
    max_line = MAXLEN;
    
    nlines = 0;
    while ((len = getline(&lpt, &max_line, stdin)) > 1) {
        if (nlines >= maxlines || (p = memory(storage, max_storage, len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], size_t nlines)
{
    while (nlines--) {
        printf("%s\n", *lineptr++);
    }
}

void quicksort(char *v[], int min, int max)
{
    int i, j;
    void swap(char *v[], int b, int c);
    
    if (min >= max)
        return;
    swap(v, min, (min + max) / 2);
    
    j = min;
    for (i = min + 1; i <= max; i++) {
        if (strcmp(*(v + i), *(v + min)) < 0)
            swap(v, ++j, i);
    }
    
    swap(v, min, j);
    quicksort(v, min, j - 1);
    quicksort(v, j + 1, max);
}

char *memory(char *buf, size_t limit, size_t amt)
{
    char *p = buf;
    int space;
    
    while (!(*(buf) == '\0' && *(buf + 1) == '\0'))
        buf++;
    
    if (buf - p > 0) {
        buf += 1;
    }
    
    space = (int) (limit - (buf - p + amt));
    
    if (space) {
        return buf;
    } else {
        return NULL;
    }
}

void swap(char *v[], int i, int j)
{
    char *temp;
    
    temp = *(v + i);
    *(v + i) = *(v + j);
    *(v + j) = temp;
}
