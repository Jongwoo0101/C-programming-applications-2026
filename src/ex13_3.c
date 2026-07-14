#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, *p;
    p = (int *)calloc(5, sizeof(int));

    for (i = 0; i < 5; i ++ ) {
        printf("p[%d] : %d ", i, p[i]);
    }
    printf("\n\n");

    for (i = 0; i < 5; i ++ ) {
        p[i] = i;
        printf("p[%d]에는 %d이 들어 있습니다.\n", i, p[i]);
    }
    printf("\n");

    free(p);
}