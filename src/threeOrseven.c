#include <stdio.h>

void threeOrseven(int end) {
    int count = 0;
    int sum = end + 1;
    float ratio = 0.0f;
    for (int i = 0; i < end; i ++ ) {
        if (i == 0) {
            continue;
        }
        if (i % 3 == 0 && i % 7 == 0) {
            count ++;
            printf("%d ", i);
        }
    }
    ratio = ((float)count / sum) * 100.0f;
    printf("\n0~%d사이에 3의 배수이면서 7의 배수인 자연수는 전체 %d개 중 %d개로 %.2f%%비율을 차지하고 있음", end, sum, count, ratio);
}

int main() {
    int numV = 0;
    printf("임의의 정수 하나(3자리)를 입력하세요 : ");
    scanf("%d", &numV);

    threeOrseven(numV);
}