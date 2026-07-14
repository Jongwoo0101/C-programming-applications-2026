/*
외부로부터 입력된 여러 개의 임의의 값 (정수)을 입력받아 
내림차순으로 정렬하여 출력하는 프로그램을 작성하시오.
정렬 기능은 사용자 정의 함수 (Sort())로 구현하시오.
- 입력 받을 정수의 개수를 사용자에게 먼저 지정하도록 하면 입력되는 정수의 개수를 결정함.
- 외부로부터 입력 받을 정수의 개수는 정해져 있지 않으므로, 여러 개의 임의의 값을 저장할 공간을 동적메모리 할당 방식으로 할당하여 활용
*/

#include <stdio.h>
#include <stdlib.h>

void Sort(int arr[], int size) {
    int temp = 0;
    for ( int i = 0; i < size - 1; i ++ ) {
        for ( int j = 0; j < size - i - 1; j ++ ) {
            if ( arr[j] < arr[j + 1] ) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for ( int i = 0; i < size; i ++ ) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n;
    printf("배열의 크기를 정하시오: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);
    for ( int i = 0; i < n; i ++ ) {
        printf("%d번째 원소를 입력하시오: ", i + 1);
        scanf("%d", &arr[i]);
    }
    Sort(arr, n);
}