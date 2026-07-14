#include <stdio.h>
#include <stdlib.h>

int main() {
    int k1 = 20000, k2;
    double f1 = 625.78, f2;
    char st1[20] = "Welcome!", st2[20];
    FILE *fp;

    printf("원래의 데이터: %s. %d, %lf\n", st1, k1, f1);

    if ((fp = fopen("src/test.dat", "w")) == NULL) {
        printf("파일 열기 오류\n");
        exit(1);
    }
    fprintf(fp, "%20s %10d %10lf\n", st1, k1, f1);
    fclose(fp);

    if ((fp = fopen("src/test.dat", "r")) == NULL) {
        printf("파일 열기 오류\n");
        exit(1);
    }

    fscanf(fp, "%20s %10d %10lf", st2, &k2, &f2);
    printf("파일의 데이터: %s, %d, %lf\n", st2, k2, f2);

    fclose(fp);

}