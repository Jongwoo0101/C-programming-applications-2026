#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = "나비, 제비야, 깝치지 마라.";
    int c;
    FILE *fp;

    // 파일 쓰기
    fp = fopen("test.dat", "w");
    if (fp != NULL)
        printf("파일 'test.dat'는 쓰기 위하여 열렸습니다.\n");
    else {
        printf("파일 'test.dat'는 쓰기 위하여 열리지 않았습니다.\n");
        exit(1);
    }

    while (*s) {
        if (fputc(*s++, fp) == EOF) {
            printf("파일 쓰기 오류\n");
            fclose(fp);
            exit(1);
        }
    }

    fclose(fp);

    // 파일 읽기
    fp = fopen("test.dat", "r");
    if (fp != NULL)
        printf("파일 'test.dat'는 읽기 위하여 열렸습니다.\n");
    else {
        printf("파일 'test.dat'는 읽기 위하여 열리지 않았습니다.\n");
        exit(1);
    }

    while ((c = fgetc(fp)) != EOF)
        putchar(c);

    printf("\n");

    fclose(fp);

    return 0;
}