#include <stdio.h>

int main() {
    int N;
    char s11, s12, s13, s14, s15, s16, s17, s18; //첫 번째 이진수 저장
    char s21, s22, s23, s24, s25, s26, s27, s28; //두 번째 이진수 저장
    printf("1. 이진수 변환기    2. 이진수 덧셈기   3. 이진수 뻴셈기\n\n");
    printf("번호를 선택하세요 : ");
    scanf("%d", &N);
    getchar(); //%c로 받는으므로 개행 버퍼 비우기
    char num = 0;
    switch(N) {
        case 1:
            printf("8비트 이진수를 입력하세요 : ");
            scanf("%c%c%c%c%c%c%c%c", &s11, &s12, &s13, &s14, &s15, &s16, &s17, &s18);
            //이진수 정수로 만들기
            if(s11 == '1') num += 128;
            if(s12 == '1') num += 64;
            if(s13 == '1') num += 32;
            if(s14 == '1') num += 16;
            if(s15 == '1') num += 8;
            if(s16 == '1') num += 4;
            if(s17 == '1') num += 2;
            if(s18 == '1') num += 1;
            printf("십진수로 %d 입니다.\n", num);
            break;
        case 2:
        case 3:
            printf("첫 번째 8비트 이진수를 입력하세요 : ");
            scanf("%c%c%c%c%c%c%c%c", &s11, &s12, &s13, &s14, &s15, &s16, &s17, &s18);
            getchar(); //%c로 받는으므로 개행 버퍼 비우기
            printf("두 번째 8비트 이진수를 입력하세요 : ");
            scanf("%c%c%c%c%c%c%c%c", &s21, &s22, &s23, &s24, &s25, &s26, &s27, &s28);
            //이진수 정수로 만들기
            char num1 = 0, num2 = 0;
            if(s11 == '1') num1 += 128;
            if(s12 == '1') num1 += 64;
            if(s13 == '1') num1 += 32;
            if(s14 == '1') num1 += 16;
            if(s15 == '1') num1 += 8;
            if(s16 == '1') num1 += 4;
            if(s17 == '1') num1 += 2;
            if(s18 == '1') num1 += 1;

            if(s21 == '1') num2 += 128;
            if(s22 == '1') num2 += 64;
            if(s23 == '1') num2 += 32;
            if(s24 == '1') num2 += 16;
            if(s25 == '1') num2 += 8;
            if(s26 == '1') num2 += 4;
            if(s27 == '1') num2 += 2;
            if(s28 == '1') num2 += 1;

            if(N == 2) {
                printf("두 이진수의 합은 ");
                num = num1 + num2;
            }
            else {
                printf("두 이진수의 차는 ");
                num = num1 - num2;
            }
            //이진수 출력
            unsigned char tmp = num;
            int mod = 128;
            while(mod > 0) {
                if(tmp / mod) {
                    printf("1");
                    tmp -= mod;
                }
                else printf("0");
                mod /= 2;
            }
            printf(" 이고, 십진수로 %d 입니다.\n", num);
            break;
    }
}