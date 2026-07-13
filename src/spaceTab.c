/*
키보드로부터 문자열을 입력받아 입력받은 문자열에서 숫자(0~9), 공백(space tab), 그 외 문자의 개수를 세어 화면에 결과를 출력하시오.
*/
#include <stdio.h>

int main() {
    char str[256];      // 입력받을 문자열을 저장할 배열
    int digitCount = 0; // 숫자 개수
    int spaceCount = 0; // 공백 개수
    int otherCount = 0; // 그 외 문자 개수
    int i = 0;          // 인덱스 변수

    printf("문자열을 입력하세요: ");
    
    // scanf("%s")는 공백을 만나면 입력을 종료하므로, 공백을 포함해 줄바꿈까지 읽는 fgets 사용
    // stdin은 키보드 입력을 의미합니다.
    fgets(str, sizeof(str), stdin);

    // 문자열의 끝을 알리는 널 문자('\0')를 만날 때까지 반복
    while (str[i] != '\0') {
        // fgets는 엔터(줄바꿈, '\n')까지 문자열에 포함시키므로 카운트에서 제외
        if (str[i] == '\n') {
            i++;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            digitCount++;
        }
        else if (str[i] == ' ' || str[i] == '\t') {
            spaceCount++;
        }
        else {
            otherCount++;
        }
        i++;
    }

    printf("숫자(0~9) 개수: %d\n", digitCount);
    printf("공백(스페이스, 탭) 개수: %d\n", spaceCount);
    printf("그 외 문자 개수: %d\n", otherCount);

    return 0;
}