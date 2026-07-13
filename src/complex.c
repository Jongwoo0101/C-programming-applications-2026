/*
복소수를 나타내는 구조체를 정의하고, 
변수 comp1, comp2를 선언하시오.
멤버 변수로 실수(real, 배정도 부동소수점 수),
허수(image, 배정도 부동 소수점 수)를 갖는다.
*/

#include <stdio.h>

// 복소수를 나타내는 구조체 정의
struct Complex {
    double real;  // 실수부 (배정도 부동소수점 수)
    double image; // 허수부 (배정도 부동소수점 수)
};

int main() {
    // 구조체 변수 comp1, comp2 선언
    struct Complex comp1;
    struct Complex comp2;

    /* 
    선언과 동시에 초기화하려면 아래와 같이 작성할 수 있습니다.
    struct Complex comp1 = { 3.5, 2.0 };  // 3.5 + 2.0i
    struct Complex comp2 = { 1.2, -4.5 }; // 1.2 - 4.5i
    */

    return 0;
}