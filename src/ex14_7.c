#include <stdio.h>

int main() {
    FILE *sfp, *dfp;
    char sfile[20] = {"src/ex14_7.c"};
    char dfile[20] = {"src/temp.c"};
    char buf[256];

    int rcnt, wcnt;

    if (((sfp = fopen(sfile, "rb")) == NULL) || ((dfp = fopen(dfile, "wb")) == NULL)) {
        fprintf(stderr, "파일 열기 실패...\n");
        return 1;
    }

    while ((rcnt = fread(buf, 1, sizeof(buf), sfp)) > 0) {
        wcnt = fwrite(buf, 1, rcnt, dfp);
        if (wcnt < 0) {
            fprintf(stderr, "파일 쓰기 오류...\n");
            return 1;
        }
    }

    printf("%s에서 %s로 복사 되었습니다.\n", sfile, dfile);
    fclose(sfp);
    fclose(dfp);

    return 0;
}