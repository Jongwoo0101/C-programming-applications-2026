/*
학생 1명의 정보를 입력 받아 총점과 평균을 구하는 프로그램을 작성하시오.
학생 1명에 대한 정보는 main()에서 입력받으며, Get()함수에서 총점과 평균을 계산한 후 main()에서 그 결과를 출력하시오
학생 1명에 대한 정보는 학번, 국어, 영어, 수학, 총점, 평균을 저장할 수 있는 Student 구조체를 활용한다
함수의 전달 방법은 값에 의한 형태로 구현하시오.
*/

#include <stdio.h>

struct Student {
    int studentNum;
    int korean;
    int english;
    int math;
    int sum;
    float average;
};

struct Student Get(struct Student s) {
    s.sum = s.korean + s.english + s.math;
    
    s.average = (float)s.sum / 3.0f;
    
    return s;
}

int main() {
    struct Student s1;
    
    printf("학번을 입력하세요: ");
    scanf("%d", &s1.studentNum);
    
    printf("국어 점수를 입력하세요: ");
    scanf("%d", &s1.korean);
    
    printf("영어 점수를 입력하세요: ");
    scanf("%d", &s1.english);
    
    printf("수학 점수를 입력하세요: ");
    scanf("%d", &s1.math);
    
    s1 = Get(s1);
    
    printf("학번: %d\n", s1.studentNum);
    printf("총점: %d\n", s1.sum);
    printf("평균: %.2f\n", s1.average);
    
    return 0;
}