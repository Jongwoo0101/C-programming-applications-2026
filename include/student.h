#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENT 5

// 학생 구조체
struct Student {
    char studentID[10];
    char studentName[10];
    int cScore;
    int pythonScore;
    int javaScore;

    int sum;
    double average;
};

// 함수 원형(프로토타입)
int getVScore(const char* subject);

void info(struct Student students[], int count);

void process(struct Student students[], int count);

void showinfo(struct Student students[], int count);

#endif