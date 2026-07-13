#include <stdio.h>

enum seasons { spring, summer, autumn, winter };
char *s_name[] = {"spring", "summer", "autumn", "winter"};

int main() {
    enum seasons s;

    s = spring;
    printf("s : %d --> season : %s\n", s, s_name[s]);

    s = winter;
    printf("s : %d --> season : %s\n", s, s_name[s]);
}