#include <stdio.h>

void sort(int arr[]) {
    int diV = 0;
    for (int i = 0; i < 6; i ++ ) {
        for (int j = 0; j < 7 - i - 1; j ++ ) {
            if (arr[j] < arr[j + 1]) {
                diV = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = diV;
            }
        }
    } 
    for (int i = 0; i < 7; i ++ ) {
        printf("%d번째 값: %d\n", i+1, arr[i]);
    }
}

int main() {
    int arr[7] = {0, };
    for (int i = 0; i < 7; i ++ ) {
        printf("%d번째 원소 값을 입력하세요: ", i + 1);
        scanf("%d", &arr[i]);
    }
    sort(arr);
}