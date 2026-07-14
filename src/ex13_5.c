#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *pa;
    long long *pb;

    pa = (int *)calloc(5, sizeof(int));

    for ( i = 0; i < 5; i ++ ) {
        pa[i] = i;
    }

    for ( i = 0; i < 5; i ++ ) {
        printf("%6d ", pa[i]);
    }
    printf("\n");

    pb = (long long *)realloc(pa, 5 * sizeof(long long));

    for ( i = 0; i < 5; i ++ ) {
        pb[i] = i * 1000;
    }

    for ( i = 0; i < 5; i ++ ) {
        printf("%6lld ", pb[i]);
    }
    printf("\n");

    free(pb);
}