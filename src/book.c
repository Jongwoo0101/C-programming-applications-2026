/*
멤버가 책 제목, 저자, 출판년도로 구성된 Book이라는 구조체를 만들고, 구조체 변수를 선언한 후 
각각의 멤버 변수에 데이터를 초기화하고, 결과를 모니터에 출력하는 프로그램을 작성하시오.
*/

#include <stdio.h>

struct Book {
    char title[40];
    char author[40];
    unsigned int year;
};

int main() {
    struct Book book1 = {"염소의 축제", "마리오 바르가스 요사", 2010};

    printf("%s\n", book1.title);
    printf("%s\n", book1.author);
    printf("%d\n", book1.year);

}