#include <stdio.h>

enum colors { black, brown, red, orange, yellow, green, blue = 16, violet, gray, white };
typedef enum colors color_band;

int main() {
    color_band code;

    int value;

    code = orange;
    printf("code = orange --> %d\n", code);

    code = gray;
    printf("code = gray --> %d\n", code);

    value = red + yellow;
    printf("value = red + yellow --> %d\n", value);
}