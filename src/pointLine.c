/*
x 좌표와 y 좌표를 가지는 점을 나타내는 구조체 Point를 정의하고,
두 점을 멤버로 가지는 직선을 나타내는 구조체 Line을 정의하시오.
구조체 Line을 이용하여 직선을 저장하고 그 직선의 길이를 구하는
프로그램을 작성하시오. 길이를 구할 때는 13장에 있는 함수 sqrt()
를 사용하시오.
*/

#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point p1;
    struct Point p2;
};

int main() {
    struct Line ln;
    float lx, ly;
    double length;

    ln.p1.x = 4;
    ln.p1.y = 6;
    ln.p2.x = 14;
    ln.p2.y = 16;

    lx = (float)(ln.p2.x - ln.p1.x);
    ly = (float)(ln.p2.y - ln.p1.y);

    length = sqrt(lx * lx + ly * ly);

    printf("p1의 좌표: (%d, %d)\n", ln.p1.x, ln.p1.y);
    printf("p2의 좌표: (%d, %d)\n", ln.p2.x, ln.p2.y);
    printf("ln의 길이: %lf\n", length);
}