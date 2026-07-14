#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char c;

    fp1 = fopen("src/ex14_2_test.c", "r");
    fp2 = fopen("src/temp.c", "w");

    if (fp1 == NULL || fp2 == NULL) {
        puts("파일1 열기 실패");
        return 1;
    }

    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp2);

    fclose(fp1);
    fclose(fp2);

    printf("ex14_2.c 파일을 temp.c 파일로 복사 하였습니다.\n");

    return 0;

}