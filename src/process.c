#include <stdio.h>

void process() {
    int zzaK = 0;
    int holS = 0;
    for (int i = 1; i < 101; i ++ ) {
        if (i % 2 == 0) {
            zzaK += i;
        }
        else {
            holS += i;
        }
    }
    printf("1부터 100 사이의 자연수 중 홀수의 합: %d\n", holS);
    printf("1부터 100 사이의 자연수 중 짝수의 합: %d\n", zzaK);
}

int main() {
    process();
}