#include <stdio.h>

typedef struct Student {
    int id;
    char name[10];
    int age;
} student;

void stuPrn (student temp) {
    printf("%d %s %d\n", temp.id, temp.name, temp.age);
}
student stuInput() {
    student temp;

    printf("학번을 입력하세요: ");
    scanf("%d", &temp.id);

    printf("이름을 입력하세요: ");
    scanf("%s", temp.name);
    
    printf("나이를 입력하세요: ");
    scanf("%d", &temp.age);

    return temp;
}

int main() {
    student stu1;

    stu1 = stuInput();
    printf("\n학번 이름 나이\n");
    printf("============================\n");
    stuPrn(stu1);
    printf("\n");
    return 0;
}