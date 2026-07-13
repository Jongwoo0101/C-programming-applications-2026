#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Circle {
    struct Point center;
    int radius;
};

int main() {
    struct Circle cir_1;

    cir_1.center.x = 4;
    cir_1.center.y = 5;
    cir_1.radius = 10;

    printf("원 cir_1의 중심점의 위치: (%d, %d)\n", cir_1.center.x, cir_1.center.y);
    printf("원 cir_1의 반경: %d\n", cir_1.radius);
}