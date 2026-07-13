#include <stdio.h>

struct Point {
    int x;
    int y;
};
typedef struct Point point;

int main() {
    struct Point A;
    point B = {5, 8};
    A.x = 3;
    A.y = 4;

    printf("A점의 좌표 값: (%d, %d)\n", A.x, A.y);
    printf("B점의 좌표 값: (%d, %d)\n", B.x, B.y);
}