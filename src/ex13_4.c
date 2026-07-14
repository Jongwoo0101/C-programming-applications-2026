#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = (char *)malloc(5 * sizeof(char));
    strcpy(str, "Good");
    puts(str);

    str = (char *)realloc(str, 15);
    strcat(str, "morning");
    puts(str);

    free(str);
}