
# 12장 사용자 정의 자료형

**예제 12.2 (ex12_2.c)**
```c
#include <stdio.h>
struct Student { 
    int id; 
    char *name; 
    int age;
};

void main() {
    struct Student Hong = {20161512, (char *)"홍길동", 21};  
    struct Student Kim;
    
    Kim.id = 20161234; 
    Kim.name = (char *)"김선달";
    Kim.age = 22;
    
    printf("학번 : %d, 이름 : %s, 나이 : %d \n", Hong.id, Hong.name, Hong.age); 
    printf("학번 : %d, 이름 : %s, 나이 : %d \n", Kim.id, Kim.name, Kim.age);
}
```

**예제 12.3 (ex12_3.c)**
```c
#include <stdio.h>
struct Point {
    int x;
    int y;
};
typedef struct Point point;

void main() {
    struct Point A;
    point B = {5, 8};
    A.x = 3;
    A.y = 4;
    printf("A점의 좌표 값: (%d, %d) \n", A.x, A.y);
    printf("B점의 좌표 값: (%d, %d) \n", B.x, B.y);
}
```

**실습문제 12.1 (px12_1.c)**
```c
#include <stdio.h>
struct Book {
    char title;
    char author;
    unsigned int year;
};

void main() {
    struct Book book1 = {"염소의 축제", "마리오 바르가스 요사", 2010};
    printf("%s\n", book1.title);
    printf("%s\n", book1.author);
    printf("%d\n", book1.year);
}
```

**예제 12.4 (ex12_4.c)**
```c
#include <stdio.h>
struct Student { 
    int id; 
    char *name; 
    int age;
};

void main() {
    int a;
    struct Student class_A = { 
        {20161001, "김선달", 22},    
        {20161002, "임꺽정", 21}, 
        {20161003, "홍길동", 20} 
    };  
    for (a=0; a<3; a++) {
        printf("학번: %d, 이름: %s, 나이: %d \n", class_A[a].id, class_A[a].name, class_A[a].age);
    } 
}
```

**예제 12.5 (ex12_5.c)**
```c
#include <stdio.h>
struct Point {
    int x;
    int y;
};
struct Circle {
    struct Point center;
    int radius;
};

void main() {
    struct Circle cir_1;
    cir_1.center.x = 4; 
    cir_1.center.y = 5; 
    cir_1.radius = 10;
    
    printf("원 cir_1의 중심점의 위치: (%d, %d) \n", cir_1.center.x, cir_1.center.y);
    printf("원 cir_1의 반경: %d \n", cir_1.radius); 
}
```

**실습문제 12.2 (px12_2.c)**
```c
#include <stdio.h> 
#include <math.h>

struct Point { 
    int x; 
    int y;
};
struct Line { 
    struct Point p1; 
    struct Point p2;
};

void main() {
    struct Line ln; 
    float lx, ly; 
    double length;
    
    ln.p1.x = 4;
    ln.p1.y = 6;
    ln.p2.x = 14;
    ln.p2.y = 16;
    
    lx = (float)(ln.p2.x - ln.p1.x);
    ly = (float)(ln.p2.y - ln.p1.y);
    length = sqrt(lx * lx + ly * ly);
    
    printf("p1의 좌표 : (%d, %d)\n", ln.p1.x, ln.p1.y);
    printf("p2의 좌표 : (%d, %d)\n", ln.p2.x, ln.p2.y);
    printf("ln의 길이 : %lf \n", length);
}
```

**예제 12.6 (ex12_6.c)**
```c
#include <stdio.h>
struct Point { 
    int x; 
    int y; 
    int z;
}; 
typedef struct Point point;

void main() {
    point A = {3, 4, 5}; 
    point B = {2, 6, 9}; 
    point *ptr1, *ptr2;
    ptr1 = &A; 
    ptr2 = &B;
    
    printf("A점의 좌표 : (%d, %d, %d) \n", A.x, A.y, A.z);
    printf("A점의 좌표 : (%d, %d, %d) \n", (*ptr1).x, (*ptr1).y, (*ptr1).z);
    printf("B점의 좌표 : (%d, %d, %d) \n", ptr2->x, ptr2->y, ptr2->z);
}
```

**실습문제 12.3 (px12_3.c)**
```c
#include <stdio.h> 
#include <math.h>

struct Point { 
    int x; 
    int y;
};
struct Line { 
    struct Point p1; 
    struct Point p2;
};

void main() {
    struct Line ln; 
    struct Line *pln = &ln; 
    float lx, ly; 
    double length;
    
    pln->p1.x = 4;
    pln->p1.y = 6;
    pln->p2.x = 14;
    pln->p2.y = 16;

    lx = (float)(pln->p2.x - pln->p1.x);
    ly = (float)(pln->p2.y - pln->p1.y);
    length = sqrt(lx * lx + ly * ly);
    
    printf("p1의 좌표 : (%d, %d)\n", pln->p1.x, pln->p1.y);
    printf("p2의 좌표 : (%d, %d)\n", pln->p2.x, pln->p2.y);
    printf("ln의 길이 : %lf \n", length);
}
```

**예제 12.7 (ex12_7.c)**
```c
#include <stdio.h>

typedef struct Student {
    int id;
    char name;
    int age;
} student;

void stuPrn(student temp);
student stuInput();

int main() {
    student stu1;
    stu1 = stuInput(); 
    printf("\n 학번 이름 나이 \n"); 
    printf("============================\n"); 
    stuPrn(stu1); 
    printf("\n"); 
    return 0;
}

void stuPrn(student temp) {
    printf("%d %s %d \n", temp.id, temp.name, temp.age); 
}

student stuInput() {
    student temp;
    printf("학번을 입력하세요: ");
    scanf_s("%d", &temp.id);
    printf("이름을 입력하세요: ");
    scanf_s("%s", temp.name, 10);
    printf("나이를 입력하세요: ");
    scanf_s("%d", &temp.age);
    return temp;
}
```

**예제 12.8 (ex12_8.c)**
```c
#include <stdio.h>

union value { 
    char c;
    int i; 
    double d;
}; 
typedef union value number;

int main() {
    number num;
    
    num.c = 61; 
    printf("num.c = %d 를 보관하는 경우\n", num.c); 
    printf(" num.c = %d, num.i = %d, num.d = %e \n", num.c, num.d, num.d);
    
    num.i = 541494;
    printf("num.i = %d 를 보관하는 경우\n", num.i);
    printf(" num.c = %d, num.i = %d, num.d = %e \n", num.c, num.d, num.d);
    
    num.d = 3.141592;
    printf("num.d = %lf 를 보관하는 경우\n", num.d);
    printf(" num.c = %d, num.i = %d, num.d = %e \n", num.c, num.i, num.d);
    
    return 0;
}
```

**예제 12.9 (ex12_9.c)**
```c
#include <stdio.h>

struct Student { 
    int id; 
    char name; 
    int age;
};

union Register { 
    char ch; 
    short int sh; 
    long int lo;
};

void main() {
    struct Student stu1; 
    union Register reg1;
    
    printf("stu1의 메모리 크기 : %d \n", sizeof(stu1));
    printf("reg1의 메모리 크기 : %d \n", sizeof(reg1));
    
    reg1.lo = 0x12345678;
    printf("reg1.ch = %8x \n", reg1.ch);
    printf("reg1.sh = %8x \n", reg1.sh);
    printf("reg1.lo = %8x \n", reg1.lo);
}
```

**예제 12.10 (ex12_10.c)**
```c
#include <stdio.h>

enum seasons { spring, summer, autumn, winter };
char *s_name[] = {"spring", "summer", "autumn", "winter"};

void main() {
    enum seasons s;
    
    s = spring;
    printf("s : %d --> season : %s \n", s, s_name[s]);
    
    s = winter;
    printf("s : %d --> season : %s \n", s, s_name[s]);
}
```

**예제 12.11 (ex12_11.c)**
```c
#include <stdio.h>

enum colors { black, brown, red, orange, yellow, green, blue = 16, violet, gray, white }; 
typedef enum colors color_band;

void main() {
    color_band code; 
    int value;
    
    code = orange; 
    printf("code = orange --> %d \n", code); 
    
    code = gray; 
    printf("code = gray --> %d \n", code); 
    
    value = red + yellow; 
    printf("value = red + yellow --> %d \n", value);
}
```

***

# 13장 동적 메모리 관리와 표준 함수

**예제 13.5 (ex13_5.c)**
```c
#include <stdio.h>
#include <stdlib.h>

void main(){
    int i;
    int *pa;
    long long *pb;

    pa = (int *)calloc(5, sizeof(int));
    for (i=0; i<5; i++)
        pa[i] = i;
    for (i=0; i<5; i++)
        printf("%6d ", pa[i]);
    printf("\n");
    
    pb = (long long *)realloc(pa, 5 * sizeof(long long));
    for (i=0; i<5; i++)
        pb[i] = i * 1000;
    for (i=0; i<5; i++)
        printf("%6lld ", pb[i]);
    printf("\n");
    
    free(pb);
}
```

**실습문제 13.1 (px13_1.c)**
```c
#include <stdio.h>
#include <stdlib.h>

void main(){
    int i;
    int *pt;
    
    pt = (int *)malloc(5 * sizeof(int));
    for (i=0; i<5; i++)
        pt[i] = 10 * i;
    for (i=0; i<5; i++)
        printf("%d ", pt[i]);
    printf("\n");
    
    pt = (int *)realloc(pt, 10 * sizeof(int));
    for (i=5; i<10; i++)
        pt[i] = 100 * i;
    for (i=0; i<10; i++)
        printf("%d ", pt[i]);
    printf("\n");
    
    free(pt);
}
```

**실습문제 13.2 (px13_2.c)**
```c
#include <stdio.h>
#include <stdlib.h>

void main() {
    int i;
    int *pt;
    
    pt = (int *)calloc(5, sizeof(int));
    pt = (int *)realloc(pt, 10 * sizeof(int));
    for (i=5; i<10; i++)
        pt[i] = 100 * i;
    for (i=0; i<10; i++)
        printf("%d ", pt[i]);
    printf("\n");
    
    free(pt);
}
```

**실습문제 13.3 (px13_3.c)**
```c
#include <stdio.h>
#include <math.h>

void main(){
    double a = 20.0;
    double diag, area;
    
    diag = sqrt(a * a + a * a);
    area = pow(diag, 2);
    
    printf("대각선의 길이 : %lf \n", diag);
    printf("넓이 : %lf \n", area);
}
```

**예제 13.6 (ex13_6.c)**
```c
#include <stdio.h>
#include <math.h>

const double pi = 3.14159;

void main() {
    int deg1 = 30, deg2 = 45;
    double rad1, rad2;
    
    rad1 = deg1 * pi / 180;
    rad2 = deg2 * pi / 180;
    
    printf("sin(%d) = %lf \n", deg1, sin(rad1));
    printf("cos(%d) = %lf \n", deg1, cos(rad1));
    printf("tan(%d) = %lf \n", deg1, tan(rad1));
    printf("\n");
    
    printf("sin(%d) = %lf \n", deg2, sin(rad2));
    printf("cos(%d) = %lf \n", deg2, cos(rad2));
    printf("tan(%d) = %lf \n", deg2, tan(rad2));
}
```

**예제 13.7 (ex13_7.c)**
```c
#include <stdio.h>
#include <math.h>

void main(){
    double a = 2, b = 25;
    printf("pow(5, 3) = %.1lf \n", pow(5.0, 3.0));
    printf("sqrt(25) = %.1lf \n", sqrt(25.0));
    printf("log10(1000) = %.1lf \n", log10(1000.0));
}
```

**예제 13.8 (ex13_8.c)**
```c
#include <stdio.h>
#include <math.h>

void main() {
    double a, b, c;
    double x, y;
    
    a = -1.0;
    x = exp(a);
    printf("exp(%lf) = %lf\n", a, x);
    
    b = log(x);
    printf("log(%lf) = %lf\n\n", x, b);
    
    a = 1.0;
    y = exp(a);
    printf("exp(%lf) = %lf\n", a, y);
    
    c = log(y);
    printf("log(%lf) = %lf\n", y, c);
}
```

**예제 13.9 (ex13_9.c)**
```c
#include <stdio.h> 
#include <math.h> 

void main() {
    double x1 = 65.156, x2 = 65.876; 
    double y, z;
    
    printf("ceil(%lf) = %lf \n", x1, ceil(x1)); 
    printf("ceil(%lf) = %lf \n\n", x2, ceil(x2));
    
    printf("floor(%lf) = %lf \n", x1, floor(x1)); 
    printf("floor(%lf) = %lf \n\n", x2, floor(x2));
    
    printf("fmod(%lf, %lf) = %lf \n", x1, y = 2.4, fmod(x1, y)); 
    z = modf(x1, &y); 
    printf("z = modf(%lf, &y) --> %lf(z) + %lf(y) \n", x1, z, y);
}
```

**예제 13.12 (ex13_12.c)**
```c
#include <stdio.h>
#include <ctype.h>

void main() {
    int ascii, cap, low;
    char ch;
    
    printf("문자를 입력하세요 : ");
    scanf_s("%c", &ch, 1);
    
    ascii = toascii(ch);
    printf("ascii = %d \n", ascii);
    
    cap = toupper(ch);
    printf("capital = %c \n", cap);
    
    low = tolower(ch);
    printf("lower = %c \n", low);
}
```

***

# 14장 파일 입출력

**예제 14.1 (ex14_1.c)**
```c
#include <stdio.h> 
#include <stdlib.h>

int main() {
    char *s = "나비, 제비야, 깝치지 마라.";  
    char c;
    FILE *fp; 
    errno_t err;
    
    err = fopen_s(&fp, "test.dat", "w"); 
    if (err == 0)
        printf("파일 'test.dat'는 쓰기 위하여 열렸습니다.\n"); 
    else {
        printf("파일 'test.dat'는 쓰기 위하여 열리지 않았습니다.\n"); 
        exit(1);
    }
    
    while (*s){ 
        if (fputc(*s++, fp) == EOF) {
            printf(" 파일쓰기 오류\n"); 
            exit(1);
        } 
    } 
    fclose(fp);
    
    err = fopen_s(&fp, "test.dat", "r"); 
    if (err == 0)
        printf("파일 'test.dat'는 읽기 위하여 열렸습니다.\n"); 
    else {
        printf("파일 'test.dat'는 읽기 위하여 열리지 않았습니다.\n"); 
        exit(1);
    }
    
    while ((c = fgetc(fp)) != EOF)
        putchar(c);
    printf("\n");
    fclose(fp);
    return 0;
}
```

**예제 14.1.1 (ex14_1_1.c) - 위 예제를 fopen() 함수로 작성**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = "나비, 제비야, 깝치지 마라.";
    char c;
    FILE *fp;
    
    fp = fopen("test.dat", "w");
    if (fp == NULL) {
        printf("파일 'test.dat'는 쓰기 위하여 열리지 않았습니다.\n");
        exit(1);
    } else {
        printf("파일 'test.dat'는 쓰기 위하여 열렸습니다.\n");
    }
    
    while (*s){
        if (fputc(*s++, fp) == EOF) {
            printf(" 파일쓰기 오류\n");
            exit(1);
        }
    }
    fclose(fp);
    
    fp = fopen("test.dat", "r");
    if (fp == NULL) {
        printf("파일 'test.dat'는 읽기 위하여 열리지 않았습니다.\n");
        exit(1);
    } else {
        printf("파일 'test.dat'는 읽기 위하여 열렸습니다.\n");
    }
    
    while ((c = fgetc(fp)) != EOF)
        putchar(c);
    printf("\n");
    fclose(fp);
    
    return 0;
}
```

**예제 14.2 (ex14_2.c) - 파일 복사**
```c
#include <stdio.h>

int main() {
    FILE *fp1, *fp2; 
    char c; 
    errno_t err1, err2;
    
    err1 = fopen_s(&fp1, "ex14_2.c", "r");  // fp1 = fopen("ex14_2.c", "r"); 
    err2 = fopen_s(&fp2, "temp.c", "w");    // fp2 = fopen("temp.c", "w");
    
    if (err1 != 0 || err2 != 0) {           // if (fp1 == NULL || fp2 == NULL) { 
        puts("파일1 열기 실패");
        return 1; 
    }
    
    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp2);
        
    fclose(fp1);
    fclose(fp2);
    
    printf_s("ex14_2.c 파일을 temp.c 파일로 복사 하였습니다.\n");
    return 0;
}
```

**실습문제 14.1 (px14_1.c)**
```c
#include <stdio.h>

int main() {
    FILE *fp;
    char fname;
    char c;
    
    printf("읽을 파일의 이름을 입력 하시오 : ");
    scanf_s("%s", fname, 20);
    
    if (fopen_s(&fp, fname, "r") != 0) {
        puts("파일 열기 실패");
        return 1;
    }
    
    while ((c = fgetc(fp)) != EOF)
        putchar(c);
        
    putchar('\n');
    fclose(fp);
    
    return 0;
}
```

**예제 14.3 (ex14_3.c)**
```c
#include <stdio.h> 
#include <stdlib.h>

int main( void ) {
    FILE *fp; 
    char line = "Hello! World.";
    
    if ( fopen_s( &fp, "test.dat", "w" ) != 0 ) {
        puts("File open error!"); 
        exit(1);
    } 
    
    if ( fputs( line, fp ) == EOF)
        puts("fputs() error" ); 
    else
        fputc('\n', fp); 
        
    puts("파일이 정상적으로 생성되었습니다.");
    fclose( fp );
    
    if ( fopen_s( &fp, "test.dat", "r" ) != 0 ) {
        puts("File open error!");
        exit(1);
    }
    
    if ( fgets( line, 20, fp ) == NULL)
        puts("fgets() error" );
    else {
        puts("읽은 파일의 내용은 : ");
        printf("%s", line);
    }
    fclose( fp );
    return 0;
}
```

**예제 14.4 (ex14_4.c)**
```c
#include <stdio.h> 
#include <stdlib.h>

void main(void) {
    int k1 = 20000, k2; 
    double f1 = 625.78, f2; 
    char st1 = "Welcome!", st2; 
    FILE *fp;
    
    printf_s("원래의 데이터: %s, %d, %lf\n", st1, k1, f1);
    
    if ((fopen_s(&fp, "test.dat", "w")) != 0) { 
        printf("파일 열기 오류\n"); 
        exit(1);
    } 
    fprintf_s(fp, "%20s %10d %10lf\n", st1, k1, f1); 
    fclose(fp);
    
    if ((fopen_s(&fp, "test.dat", "r")) != 0) {
        printf("파일 열기 오류\n");
        exit(1);
    }
    fscanf_s(fp, "%20s %10d %10lf", st2, 20, &k2, &f2);
    printf_s("파일의 데이터: %s, %d, %lf\n", st2, k2, f2);
    fclose(fp);
}
```

**예제 14.5 (ex14_5.c)**
```c
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main() {
    char *s = "맨드라미 들마꽃에도 인사를 해야지.";  
    char c;
    FILE *fp; 
    errno_t err; 
    char errmsg;
    
    err = fopen_s(&fp, "test.dat", "w"); 
    if (err != 0) {
        printf("파일 열기 오류\n"); 
        exit(1);
    }
    
    while (*s){
        if (fputc(*s++, fp) == EOF) {
            printf(" 파일 쓰기 오류\n");
            exit(1);
        }
    }
    fclose(fp);
    
    err = fopen_s(&fp, "test.dat", "r");
    if (err != 0) {
        strerror_s(errmsg, 80, err);
        printf("오류 : %s \n", errmsg);
        exit(1);
    }
    
    while (!feof(fp)) {
        c = fgetc(fp);
        putchar(c);
        if (ferror(fp)) {
            printf("파일 오류\n");
            break;
        }
    }
    printf("\n");
    fclose(fp);
    return 0;
}
```

**예제 14.5.1 (ex14_5_1.c) - 위 예제를 fopen(), strerror() 사용**
```c
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main() {
    char *s = "맨드라미 들마꽃에도 인사를 해야지.";  
    char c;
    FILE *fp;
    
    fp = fopen("test.dat", "w"); 
    if (fp == NULL) {
        printf("파일 열기 오류\n"); 
        exit(1);
    }
    
    while (*s){
        if (fputc(*s++, fp) == EOF) {
            printf(" 파일 쓰기 오류\n");
            exit(1);
        }
    }
    fclose(fp);
    
    fp = fopen("test.dat", "r");
    if (fp == NULL) {
        printf("파일 열기 오류: %s\n", strerror(errno)); // errno.h 사용 필요
        exit(1);
    }
    
    while (!feof(fp)) {
        c = fgetc(fp);
        putchar(c);
        if (ferror(fp)) {
            printf("파일 오류\n");
            break;
        }
    }
    printf("\n");
    fclose(fp);
    return 0;
}
```

**예제 14.6 (ex14_6.c) - 이진 파일**
```c
#include <stdio.h> 
#include <stdlib.h>

int main() { 
    FILE *fp; 
    int a = {1, 2, 3, 4, 5}; 
    int i, b;
    
    if ((fopen_s(&fp, "test.dat", "wb")) != 0) { 
        puts("쓰기 위해 파일 열기 실패");   
        exit(1);
    } 
    if (fwrite(a, sizeof(int), 5, fp) != 5) {
        puts("파일에 기록 오류");   
        exit(1);
    } 
    fclose(fp);
    
    if ((fopen_s(&fp, "test.dat", "rb")) != 0) {
        puts("읽기 위해 파일 열기 실패");
        exit(1);
    }
    if (fread(b, sizeof(int), 5, fp) != 5) {
        puts("파일로부터 읽기 오류");
        exit(1);
    }
    fclose(fp);
    
    for (i=0; i<5; i++)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}
```

**예제 14.7 (ex14_7.c)**
```c
#include <stdio.h>

int main() {
    FILE *sfp, *dfp;
    char sfile = {"ex14_7.c"};
    char dfile = {"temp.c"};
    char buf;
    int rcnt, wcnt;
    
    if ((fopen_s(&sfp, sfile, "rb") != 0) || (fopen_s(&dfp, dfile, "wb") != 0)) {
        fprintf(stderr, "파일 열기 실패...\n");
        return 1;
    }
    
    while ((rcnt = fread(buf, 1, sizeof(buf), sfp)) > 0) {
        wcnt = fwrite(buf, 1, rcnt, dfp);
        if (wcnt < 0) {
            fprintf(stderr, "파일 쓰기 오류...\n");
            return 1;
        }
    }
    printf("%s에서 %s로 복사 되었습니다\n", sfile, dfile);
    fclose(sfp);
    fclose(dfp);
    return 0;
}
```

**예제 14.8 (ex14_8.c) - 파일 임의 접근**
```c
#include <stdio.h> 
#include <stdlib.h>

typedef struct Nobel_Literature { 
    char title; 
    char author; 
    unsigned int year;
} NOBEL;

#define RECLEN 86 
#define FORMAT "%-40s%-40s%6d" 
FILE *fp; 

void datawrite(int, char *, char *, int); 
void dataread(NOBEL *);

void main() {
    int i; 
    NOBEL nbook;
    
    if ((fopen_s(&fp, "booklist.dat", "wb")) != 0) { 
        puts("파일 읽기 에러");   
        exit(1);
    } 
    datawrite(0, "염소의 축제", "마리오 바르가스 요사", 2010);
    datawrite(1, "기억이 나를 본다", "토마스 트란스트뢰메르", 2011);  
    datawrite(2, "사부님은 갈수록 유머러스해진다", "모옌", 2012);  
    fclose(fp);
    
    if ((fopen_s(&fp, "booklist.dat", "rb")) != 0) {
        puts("파일 읽기 에러"); exit(1);
    }
    for (i=0; i<3; i++) { 
        dataread(&nbook); 
        printf_s("%d\t제목 : %40s\n\t작가 : %20s \n\t수상년도 : %d \n\n",
                 i, nbook.title, nbook.author, nbook.year); 
    }
}

void datawrite(int recno, char *title, char *author, int year) {
    fseek(fp, RECLEN *recno, SEEK_SET); 
    fprintf_s(fp, FORMAT, title, author, year);
}

void dataread(NOBEL *nbook) {
    fgets(nbook->title, 41, fp);
    fgets(nbook->author, 41, fp);
    fscanf_s(fp, "%d", &nbook->year);
}
```

**실습문제 14.2 (px14_2.c)**
```c
#include <stdio.h> 
#include <stdlib.h>

typedef struct Nobel_Literature { 
    char title; 
    char author; 
    unsigned int year;
} NOBEL;

#define RECLEN 86 
#define FORMAT "%-40s%-40s%6d\n"

FILE *fp; 
void datawrite(int, char *, char *, int); 
void dataread(int, NOBEL *);

void main() {
    int rno;    
    NOBEL nbook; 
    
    if ((fopen_s(&fp, "booklist.dat", "wb")) != 0) {
        puts("파일 읽기 에러");   
        exit(1);
    } 
    datawrite(0, "염소의 축제", "마리오 바르가스 요사", 2010);
    datawrite(1, "기억이 나를 본다", "토마스 트란스트뢰메르", 2011);  
    datawrite(2, "사부님은 갈수록 유머러스해진다", "모옌", 2012);  
    fclose(fp);
    
    if ((fopen_s(&fp, "booklist.dat", "rb")) != 0) { 
        puts("파일 읽기 에러");
        exit(1); 
    } 
    printf("출력할 레코드 번호를 입력 하세요: ");
    scanf_s("%d", &rno); 
    dataread(rno, &nbook);
}

void datawrite(int recno, char *title, char *author, int year) {
    fseek(fp, RECLEN *recno, SEEK_SET); 
    fprintf_s(fp, FORMAT, title, author, year);
}

void dataread(int recno, NOBEL *nbook) {
    fseek(fp, recno * RECLEN, SEEK_SET); 
    fgets(nbook->title, 41, fp); 
    fgets(nbook->author, 41, fp); 
    fscanf_s(fp,"%d", &nbook->year); 
    printf_s("%d\t제목 : %40s\n\t작가 : %20s \n\t수상년도 : %d \n\n",
             recno, nbook->title, nbook->author, nbook->year); 
}
```

**예제 14.9 (ex14_9.c)**
```c
#include <stdio.h> 
#include <stdlib.h>

int main() { 
    FILE *fp; 
    char *buf; 
    int fsize;
    
    if ((fopen_s(&fp, "ex14_9.c", "rb")) != 0) {
        fprintf(stderr, "파일 열기 실패...\n"); 
        return 1;
    }
    
    fseek(fp, 0, SEEK_END); 
    fsize = ftell(fp); 
    buf = (char *)malloc(fsize * sizeof(char) + 1);
    
    rewind(fp);
    if (fread(buf, 1, fsize, fp) < 1) {
        fprintf(stderr, "파일 읽기 오류...\n");
        return 1;
    }
    
    buf[fsize] = '\0';
    fclose(fp);
    
    puts("다음은 읽은 파일의 내용입니다.");
    puts(buf);
    
    return 0;
}
```