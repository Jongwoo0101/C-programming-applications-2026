#include <stdio.h>
#include <stdlib.h>
#define RECLEN 86
#define FORMAT "%-40s%-40s%6d"

FILE *fp;

typedef struct Nobel_Literature {
    char title[41];
    char author[41];
    unsigned int year;
} NOBEL;


void datawrite(int recno, char *title, char *author, int year) {
    fseek(fp, RECLEN *recno, SEEK_SET);
    fprintf(fp, FORMAT, title, author, year);
} 
void dataread(NOBEL *nbook) {
    fgets(nbook -> title, 41, fp);
    fgets(nbook -> author, 41, fp);
    fscanf(fp, "%d", &nbook -> year);
}

int main() {
    int i;
    NOBEL nbook;

    if ((fp = fopen("src/booklist.dat", "wb")) == NULL) {
        puts("파일 읽기 에러");
        exit(1);
    }

    datawrite(0, "염소의 축제", "마리오 바르가스 요사", 2010);
    datawrite(1, "기억이 나를 본다", "토마스 트란스트뢰메르", 2011);
    datawrite(2, "사부님은 갈수록 유머러스해진다", "모옌", 2012);
    
    fclose(fp);

    if ((fp = fopen("src/booklist.dat", "rb")) == NULL) {
        puts("파일 읽기 에러");
        exit(1);
    }

    for (i = 0; i < 3; i ++ ) {
        dataread(&nbook);
        printf("%d\t제목 : %40s\n\t작가 : %20s\n\t수상년도 : %d\n\n", i, nbook.title, nbook.author, nbook.year);
    }
}