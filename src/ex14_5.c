#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = "맨드라미 들마꽃에도 인사를 해야지.";
    int c;              // EOF와 비교하기 위해 int 사용
    FILE *fp;

    // 파일 쓰기
    fp = fopen("test.dat", "w");
    if (fp == NULL) {
        perror("파일 열기 오류");
        exit(1);
    }

    while (*s) {
        if (fputc(*s++, fp) == EOF) {
            perror("파일 쓰기 오류");
            fclose(fp);
            exit(1);
        }
    }

    fclose(fp);

    // 파일 읽기
    fp = fopen("test.dat", "r");
    if (fp == NULL) {
        perror("파일 열기 오류");
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    if (ferror(fp)) {
        printf("파일 읽기 오류\n");
    }

    printf("\n");

    fclose(fp);

    return 0;
}