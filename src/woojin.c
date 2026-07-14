#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point *arr;

    arr = (struct Point *)calloc(3, sizeof(struct Point));

    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    arr = (struct Point *)realloc(arr, 5 * sizeof(struct Point));

    if (arr == NULL) {
        printf("메모리 재할당 실패\n");
        return 1;
    }

    free(arr);
    arr = NULL;

    return 0;
}