/*
다음과 같은 동적 메모리 할당의 프로그램을 작성하시오. 크기 5의
int형 배열을 동적으로 생성하고, 배열의 원소에 0, 10, 20, 30, 40을
저장하고 출력한다. 이 배열을 크기 10의 int형 배열로 메모리 재할
당하고, 추가로 할당된 원소에는 500, 600, 700, 800, 900을 저장하
고 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *pt;

    pt = (int *)malloc(5 * sizeof(int));

    for ( i = 0; i < 5; i ++ ) {
        pt[i] = 10 * i;
    }
    for ( i = 0; i < 5; i ++ ) {
        printf("%d ", pt[i]);
    } 
    printf("\n");

    pt = (int *)realloc(pt, 10 * sizeof(int));

    for ( i = 5; i < 10; i ++ ) {
        pt[i] = 100 * i;
    }

    for ( i = 0; i < 10; i ++ ) {
        printf("%d ", pt[i]);
    }
    printf("\n");

    free(pt);
}