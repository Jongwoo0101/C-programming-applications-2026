#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int a[5] = {1, 2, 3, 4, 5};
    int i, b[5];

    if ((fp = fopen("src/test.dat", "wb")) == NULL) {
        puts("쓰기 위해 파일 열기 실패");
        exit(1);
    }

    if (fwrite(a, sizeof(int), 5, fp) != 5) {
        puts("파일에 기록 오류");
        exit(1);
    }
    fclose(fp);

    if ((fp = fopen("src/test.dat", "rb")) == NULL) {
        puts("쓰기 위해 파일 열기 실패");
        exit(1);
    }

    if (fread(b, sizeof(int), 5, fp) != 5) {
        puts("파일로부터 읽기 오류");
        exit(1);
    }
    fclose(fp);

    for ( i = 0; i < 5; i ++ ) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}