#include <stdio.h>

struct Student {
    int id;
    char *name; // 문자 하나를 저장하는 것이 아니라, 문자열의 시작 주소를 저장하는 포인터.
    int age;
};

int main() {
    struct Student Hong = {20161512, (char *)"홍길동", 21};
    struct Student Kim;
    Kim.id = 20161234;
    Kim.name = (char *)"김선달";
    Kim.age = 22;

    printf("학번 : %d, 이름 : %s, 나이 : %d\n", Hong.id, Hong.name, Hong.age);
    printf("학번 : %d, 이름 : %s, 나이 : %d\n", Kim.id, Kim.name, Kim.age);
}