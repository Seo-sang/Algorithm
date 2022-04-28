#include <stdio.h>

int main()
{
    int num;
    _Bool bit;
    printf("-128부터 127까지의 십진수 정수 하나를 입력하세요 : ");
    scanf("%d", &num);

    printf("-128의 이진수는 ");
    for(int i = 7; i >= 0; i--) {
        bit = num & (1 << i);
        printf("%d", bit);
        if(i == 4) printf(" ");
    }
    printf(" 입니다.\n");
}
