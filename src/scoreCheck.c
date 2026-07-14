#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 20

// 조건 3. 성적정보(grad) 구조체 정의 (파이썬, 자바, C언어 점수)
typedef struct {
    int python;
    int java;
    int c_lang;
    int has_grades; // 성적 입력 여부를 확인하기 위한 플래그
} grad;

// 조건 2, 4 학생정보(student) 구조체 정의 (학번, 이름, 나이, 성적정보 포함 -> 구조체 중첩)
typedef struct {
    char student_id[20];
    char name[20];
    int age;
    grad grades; // 하위 구조체 포함
} student;

// 함수 원형 선언
// 조건 1. 전체 5개의 메뉴 제공 화면 (학생 정보 입력, 개별 성적 입력, 반별 성적 확인, 과목별 최고 득점자 확인, 정보 저장, 프로그램 종료)
void print_menu() {
    printf("\n========================================\n");
    printf("         성적확인 프로그램         \n");
    printf("========================================\n");
    printf("  1: 학생 정보 입력\n");
    printf("  2: 개별 성적 입력\n");
    printf("  3. 반별 성적 확인\n");
    printf("  4. 과목별 최고 득점자 확인\n");
    printf("  5. 정보 저장\n");
    printf("  0. 프로그램 종료\n");
    printf("=> 실행할 메뉴를 선택하세요 : ");
}

// 조건 6. 1번 메뉴: 학생 기본정보(학번, 이름, 나이) 입력
void input_student_info(student* list, int* count) {
    if (*count >= MAX_STUDENTS) {
        printf("\n더 이상 학생 정보를 입력할 수 없습니다. (최대 20명)\n");
        return;
    }
    printf("\n[1. 학생 정보 입력]\n");
    printf("학번을 입력하세요: ");
    scanf("%s", list[*count].student_id);
    printf("이름을 입력하세요: ");
    scanf("%s", list[*count].name);
    printf("나이를 입력하세요: ");
    scanf("%d", &list[*count].age);

    list[*count].grades.has_grades = 0; // 성적 미입력 상태로 초기화
    (*count)++;
    printf("-> 학생 정보가 정상적으로 등록되었습니다.\n");
}

// 조건 7. 2번 메뉴: 개별 성적 입력 (학생정보가 입력되어 있는 경우에만 가능)
void input_grades(student* list, int count) {
    char target_id[20];
    int found_index = -1;

    if (count == 0) {
        printf("\n등록된 학생 정보가 없습니다. 먼저 학생 정보를 입력하세요.\n");
        return;
    }

    printf("\n[2. 개별 성적 입력]\n");
    printf("성적을 입력할 학생의 학번을 입력하세요: ");
    scanf("%s", target_id);

    // 학번 검색
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].student_id, target_id) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("-> 해당 학번의 학생을 찾을 수 없습니다.\n");
        return;
    }

    printf("-> %s 학생의 성적을 입력합니다.\n", list[found_index].name);
    printf("파이썬 점수: ");
    scanf("%d", &list[found_index].grades.python);
    printf("자바 점수: ");
    scanf("%d", &list[found_index].grades.java);
    printf("C언어 점수: ");
    scanf("%d", &list[found_index].grades.c_lang);

    list[found_index].grades.has_grades = 1; // 성적 입력 완료 상태로 변경
    printf("-> 성적 입력이 완료되었습니다.\n");
}

// 조건 8. 3번 메뉴: 반별 성적 확인 (기본정보 + 교과목별 성적 + 평균)
void print_all_students(student* list, int count) {
    if (count == 0) {
        printf("\n등록된 학생 정보가 없습니다.\n");
        return;
    }

    printf("\n[3. 반별 성적 확인]\n");
    printf("%-15s %-10s %-5s %-10s %-10s %-10s %-10s\n", "학번", "이름", "나이", "파이썬", "자바", "C언어", "평균");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-15s %-10s %-5d ", list[i].student_id, list[i].name, list[i].age);
        
        if (list[i].grades.has_grades == 1) {
            double avg = (list[i].grades.python + list[i].grades.java + list[i].grades.c_lang) / 3.0;
            printf("%-10d %-10d %-10d %-10.2f\n", list[i].grades.python, list[i].grades.java, list[i].grades.c_lang, avg);
        } else {
            printf("%-10s %-10s %-10s %-10s\n", "-", "-", "-", "미입력");
        }
    }
}

// 조건 9. 4번 메뉴: 과목별 최고 득점자 확인
void print_top_scorers(student* list, int count) {
    if (count == 0) {
        printf("\n등록된 학생 정보가 없습니다.\n");
        return;
    }

    int max_py = -1, max_ja = -1, max_c = -1;
    int idx_py = -1, idx_ja = -1, idx_c = -1;

    for (int i = 0; i < count; i++) {
        if (list[i].grades.has_grades == 1) {
            if (list[i].grades.python > max_py) { max_py = list[i].grades.python; idx_py = i; }
            if (list[i].grades.java > max_ja) { max_ja = list[i].grades.java; idx_ja = i; }
            if (list[i].grades.c_lang > max_c) { max_c = list[i].grades.c_lang; idx_c = i; }
        }
    }

    printf("\n[4. 과목별 최고 득점자 확인]\n");
    if (idx_py != -1) {
        printf("- 파이썬 최고점: %s (학번: %s) / %d점\n", list[idx_py].name, list[idx_py].student_id, max_py);
    } else {
        printf("- 파이썬: 성적이 입력된 학생이 없습니다.\n");
    }
    
    if (idx_ja != -1) {
        printf("- 자바   최고점: %s (학번: %s) / %d점\n", list[idx_ja].name, list[idx_ja].student_id, max_ja);
    }
    
    if (idx_c != -1) {
        printf("- C언어  최고점: %s (학번: %s) / %d점\n", list[idx_c].name, list[idx_c].student_id, max_c);
    }
}

// 조건 10. 5번 메뉴: 정보 저장 (CSV 형태의 텍스트 파일로 저장)
void save_to_file(student* list, int count) {
    if (count == 0) {
        printf("\n저장할 학생 정보가 없습니다.\n");
        return;
    }

    FILE *fp = fopen("student_grades.txt", "w");
    if (fp == NULL) {
        printf("\n파일을 생성하거나 열 수 없습니다.\n");
        return;
    }

    fprintf(fp, "학번,이름,나이,파이썬,자바,C언어,평균\n");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%d,", list[i].student_id, list[i].name, list[i].age);
        if (list[i].grades.has_grades == 1) {
            double avg = (list[i].grades.python + list[i].grades.java + list[i].grades.c_lang) / 3.0;
            fprintf(fp, "%d,%d,%d,%.2f\n", list[i].grades.python, list[i].grades.java, list[i].grades.c_lang, avg);
        } else {
            fprintf(fp, "-,-,-,미입력\n");
        }
    }

    fclose(fp);
    printf("\n-> 학생 정보와 성적이 'student_grades.txt' 파일로 성공적으로 저장되었습니다.\n");
}

int main() {
    // 조건 5. 구조체를 활용하여 동적으로 메모리 공간 할당 (최대 20명)
    student* student_list = (student *)malloc(sizeof(student) * MAX_STUDENTS);
    if (student_list == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return -1;
    }

    int student_count = 0;
    int choice;

    // 조건 11. 기능 수행 완료 후 다시 메인 메뉴 제공, 0 입력 시 종료
    while (1) {
        print_menu();
        scanf("%d", &choice);
        while (getchar() != '\n'); // 입력 버퍼 비우기

        switch (choice) {
            case 1: 
                input_student_info(student_list, &student_count); 
                break;
            case 2: 
                input_grades(student_list, student_count); 
                break;
            case 3: 
                print_all_students(student_list, student_count); 
                break;
            case 4: 
                print_top_scorers(student_list, student_count); 
                break;
            case 5: 
                save_to_file(student_list, student_count); 
                break;
            case 0:
                printf("\n프로그램을 종료합니다.\n");
                free(student_list);
                return 0;
            default:
                printf("\n잘못된 입력입니다. 0~5 사이의 메뉴를 선택해주세요.\n");
        }
    }
    return 0;
}