#include <stdio.h>

char str1[9];
char str2[9];
char s11, s12, s13, s14, s15, s16, s17, s18, s19;
char s21, s22, s23, s24, s25, s26, s27, s28, s29;

void converter() {
    int result = 0;
    printf("8비트 이진수를 입력하세요 : ");
    scanf("%c%c%c%c%c%c%c%c%c", &s11, &s12, &s13, &s14, &s15, &s16, &s17, &s18, &s19);
    if(s11 == '1') {
        result += 128;
    }
}

void adder() {
    printf("첫 번째 8비트 이진수를 입력하세요 : ");
    scanf("%s", str1);
    printf("두 번째 8비트 이진수를 입력하세요 : ");
    scanf("%s", str2);
}

void substractor() {
    printf("첫 번째 8비트 이진수를 입력하세요 : ");
    scanf("%s", str1);
    printf("두 번째 8비트 이진수를 입력하세요 : ");
    scanf("%s", str2);
}

int main() {
    int num;
    printf("1. 이진수 변환기    2. 이진수 덧셈기   3. 이진수 뻴셈기\n\n");
    printf("번호를 선택하세요 : ");
    scanf("%d", &num);
    switch(num) {
        case 1:
            converter();
            break;
        case 2:
            adder();
            break;
        case 3:
            substractor();
            break;
    }
}