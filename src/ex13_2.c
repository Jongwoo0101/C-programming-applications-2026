#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *sptr;
    sptr = (char *)malloc(15 * sizeof(char));

    if (sptr == NULL) {
        printf("Insufficient memory\n");
        return 1;
    }

    strcpy(sptr, "Hello! World.");
    printf("%s\n", sptr);
    
    free(sptr);

    return 0;
}