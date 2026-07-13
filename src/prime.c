#include <stdio.h>

int isPrime(int n) {
    if (n < 2) {
        return 0; 
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1; 
}

int main() {
    int num;
    printf("정수를 입력하세요: ");
    scanf("%d", &num);
    
    if (isPrime(num)) {
        printf("%d는 소수입니다.\n", num);
    } 
    else {
        printf("%d는 소수가 아닙니다.\n", num);
    }
    return 0;
}
