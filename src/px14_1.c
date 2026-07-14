#include <stdio.h>

int main(void) {
    FILE *fp;
    char fname[20];
    int c;

    printf("읽을 파일의 이름을 입력하시오 : ");
    scanf("%19s", fname);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        puts("파일 열기 실패");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
        putchar(c);

    putchar('\n');

    fclose(fp);

    return 0;
}