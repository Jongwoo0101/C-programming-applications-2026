/*
다음과 같은 동적 메모리 할당의 프로그램을 작성하시오. 크기 5의
int형 배열을 calloc() 함수를 사용하여 동적으로 생성하고, 다시 이
배열을 크기 10의 int형 배열로 메모리 재할당하고, 추가로 할당된
원소에는 500, 600, 700, 800, 900을 저장하고 출력하는 프로그램으
로 고쳐 작성하시오.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = (int *)calloc(5, sizeof(int));
    array = realloc(array, 10 * sizeof(int));

    for ( int i = 5; i < 10; i ++ ) {
        array[i] = 100 * i;
    }
    for ( int i = 0; i < 10; i ++ ) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}