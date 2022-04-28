#include <stdio.h>

int main() {
    int input, i = 128;
    unsigned char num;
    printf("-128부터 127까지의 십진수 정수 하나를 입력하세요 : ");
    scanf("%d", &input);
    printf("-128의 이진수는 ");
    num = input;
    while(i) {
        printf("%d", num / i);
        if(i == 16)
            printf(" ");
        num %= i;
        i /= 2;
    }
    printf(" 입니다.\n");
}