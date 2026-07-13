#include <stdio.h>

#define MAX_STUDENT 5

struct Student {
    char studentID[10];
    char studentName[10];
    int cScore;
    int pythonScore;
    int javaScore;
    
    int sum;
    double average;
};

// 점수 유효성 검사 전용 함수 (0 ~ 100) 사이의 값이 입력이 안 되었을 때 다시 입력하라고 출력 후 반환
int getVScore(const char* subject) {
    int score;
    while (1) {
        printf("%s 점수를 입력하세요(0~100): ", subject);
        scanf("%d", &score);
        
        if (score >= 0 && score <= 100) {
            return score;
        }
        
        printf("0에서 100 사이의 점수만 입력 가능합니다. 다시 입력해주세요.\n");
    }
}

// 정보 입력 함수
void info(struct Student students[], int count) {
    for (int i = 0; i < count; i ++ ) {
        printf("\n[%d번째 학생 정보 입력]\n", i + 1);
        printf("학번을 입력하세요: ");
        scanf("%s", students[i].studentID);

        printf("학생 이름을 입력하세요: ");
        scanf("%s", students[i].studentName);
        
        students[i].cScore = getVScore("C언어");
        students[i].pythonScore = getVScore("파이썬");
        students[i].javaScore = getVScore("자바");
    }
    printf("\n");
}

// 총점 및 평균 계산 함수
void process(struct Student students[], int count) {
    for (int i = 0; i < count; i ++ ) {
        students[i].sum = students[i].cScore + students[i].pythonScore + students[i].javaScore;
        // 3.0으로 나누어 소수점 이하 값을 보존
        students[i].average = students[i].sum / 3.0; 
    }
}

// 정보 출력 함수
void showinfo(struct Student students[], int count) {

    printf("=============================================================\n");
    printf("No.\t\t이름\tC언어\t파이썬\t자바\t총점\t평균\n");
    printf("=============================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%d\t%d\t%d\t%d\t%.1f\n",
               students[i].studentID,
               students[i].studentName,
               students[i].cScore,
               students[i].pythonScore,
               students[i].javaScore,
               students[i].sum,
               students[i].average);
    }

    printf("=============================================================\n");

    int maxIdx = 0;
    int minIdx = 0;

    for (int i = 1; i < count; i ++ ) {
        if (students[i].sum > students[maxIdx].sum)
            maxIdx = i;
        if (students[i].sum < students[minIdx].sum)
            minIdx = i;
    }

    printf("\n최고점을 받은 학생은 %s 학생으로 총점 %d점, 평균 %.1f입니다.\n",
           students[maxIdx].studentName,
           students[maxIdx].sum,
           students[maxIdx].average);

    printf("최저점을 받은 학생은 %s 학생으로 총점 %d점, 평균 %.1f입니다.\n",
           students[minIdx].studentName,
           students[minIdx].sum,
           students[minIdx].average);
}
int main() {
    // 전체 학생 5명을 저장할 구조체 배열 선언
    struct Student students[MAX_STUDENT];

    // 정보 입력 (배열 자체를 인자로 전달하여 Call by Reference 수행)
    info(students, MAX_STUDENT);

    // 총점, 평균 산출
    process(students, MAX_STUDENT);

    // 최종 결과 및 정보 출력
    showinfo(students, MAX_STUDENT);

    return 0;
}