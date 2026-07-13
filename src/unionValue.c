#include <stdio.h>

union value {
    char c;
    int i;
    double d;
};

typedef union value number;

int main() {
    number num;

    num.c = 61;
    printf("num.c = %d를 보관하는 경우\n", num.c);
    printf("num.c = %d, num.i = %d, num.d = %e\n", num.c, num.i, num.d);

    num.i = 541494;
    printf("num.i = %d를 보관하는 경우\n", num.i);
    printf("num.c = %d, num.i = %d, num.d = %e\n", num.c, num.i, num.d);

    num.d = 3.141592;
    printf("num.d = %lf를 보관하는 경우\n", num.d);
    printf("num.c = %d, num.i = %d, num.d = %e\n", num.c, num.i, num.d);

}