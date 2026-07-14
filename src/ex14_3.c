#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char line[20] = "Hello! World.";

    if ((fp = fopen("src/test.dat", "w")) == NULL) {
        puts("File open error!");
        exit(1);
    }

    if (fputs( line, fp ) == EOF) {
        puts("fputs() error");
    }
    else {
        fputc('\n', fp);
    }
    puts("파일이 정상적으로 생성되었습니다.");

    fclose(fp);

    if ((fp = fopen("src/test.dat", "r")) == NULL) {
        puts("File open error!");
        exit(1);
    }
    
    if (fgets(line, 20, fp) == NULL) {
        puts("fgets() error");
    }
    else {
        puts("읽은 파일의 내용은 : ");
        printf("%s", line);
    }
    
    fclose(fp);
} 