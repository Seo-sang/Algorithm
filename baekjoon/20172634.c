#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char name[20][10];
int id[20];
int score[20];


void NameAscending() {
    char tmpName[10];
    int tmpId, tmpScore;

    printf("이름        학번        점수\n");
    for(int i = 0; i < 20; i++) {
        int idx = i;
        for(int j = i + 1; j < 20; j++) 
            if(strcmp(name[idx], name[j]) > 0)
                idx = j;

        strcpy(tmpName, name[idx]);
        strcpy(name[idx], name[i]);
        strcpy(name[i], tmpName);

        tmpId = id[idx];
        id[idx] = id[i];
        id[i] = tmpId;

        tmpScore = score[idx];
        score[idx] = score[i];
        score[i] = tmpScore;

        printf("%-12s%-12d%-3d\n", name[i], id[i], score[i]);
    }
}

void IdAscending() {
    char tmpName[10];
    int tmpId, tmpScore;

    printf("이름        학번        점수\n");
    for(int i = 0; i < 20; i++) {
        int idx = i;
        for(int j = i + 1; j < 20; j++) 
            if(id[idx] > id[j])
                idx = j;

        strcpy(tmpName, name[idx]);
        strcpy(name[idx], name[i]);
        strcpy(name[i], tmpName);

        tmpId = id[idx];
        id[idx] = id[i];
        id[i] = tmpId;

        tmpScore = score[idx];
        score[idx] = score[i];
        score[i] = tmpScore;

        printf("%-12s%-12d%-3d\n", name[i], id[i], score[i]);
    }
}

void ScoreDescending() {
    char tmpName[10];
    int tmpId, tmpScore;

    printf("이름        학번        점수\n");
    for(int i = 0; i < 20; i++) {
        int idx = i;
        for(int j = i + 1; j < 20; j++) 
            if(score[idx] < score[j])
                idx = j;

        strcpy(tmpName, name[idx]);
        strcpy(name[idx], name[i]);
        strcpy(name[i], tmpName);

        tmpId = id[idx];
        id[idx] = id[i];
        id[i] = tmpId;

        tmpScore = score[idx];
        score[idx] = score[i];
        score[i] = tmpScore;

        printf("%-12s%-12d%-3d\n", name[i], id[i], score[i]);
    }
}

void NameSearch() {
    printf("이름을 입력하세요 : ");
    char inputName[10];
    scanf("%s", inputName);
    printf("\n");
    for(int i = 0; i < 20; i++) {
        if(strcmp(inputName, name[i]) == 0) {
            printf("이름        학번        점수\n");
            printf("%-12s%-12d%-3d\n", name[i], id[i], score[i]);
            return;
        }
    }

    printf("%s 학생이 없습니다.\n", inputName);
}

int main() {
    strcpy(name[0], "Sophia"), strcpy(name[1], "Olivia");
    strcpy(name[2], "Riley"), strcpy(name[3], "Emma");
    strcpy(name[4], "Ava"), strcpy(name[5], "Isabella");
    strcpy(name[6], "Aria"), strcpy(name[7], "Amelia");
    strcpy(name[8], "Mia"), strcpy(name[9], "Liam");
    strcpy(name[10], "Noah"), strcpy(name[11], "Jackson");
    strcpy(name[12], "Aiden"), strcpy(name[13], "Elijah");
    strcpy(name[14], "Grayson"), strcpy(name[15], "Lucas");
    strcpy(name[16], "Oliver"), strcpy(name[17], "Caden");
    strcpy(name[18], "Mateo"), strcpy(name[19], "David");

    id[0] = 20220001, id[1] = 20220010;
    id[2] = 20220002, id[3] = 20220015;
    id[4] = 20220009, id[5] = 20220014;
    id[6] = 20220020, id[7] = 20220005;
    id[8] = 20220016, id[9] = 20220008;
    id[10] = 20220012, id[11] = 20220004;
    id[12] = 20220018, id[13] = 20220017;
    id[14] = 20220003, id[15] = 20220013;
    id[16] = 20220007, id[17] = 20220019;
    id[18] = 20220011, id[19] = 20220006;

    score[0] = 98, score[1] = 96;
    score[2] = 88, score[3] = 77;
    score[4] = 82, score[5] = 93;
    score[6] = 84, score[7] = 79;
    score[8] = 90, score[9] = 80;
    score[10] = 89, score[11] = 99;
    score[12] = 78, score[13] = 83;
    score[14] = 92, score[15] = 71;
    score[16] = 72, score[17] = 68;
    score[18] = 96, score[19] = 76;

    int input;
    bool loop = true;

    while(loop) {
        printf("\n1. 이름 오름차순 출력    2. 학번 오름차순 출력\n3. 점수 내림차순 출력    4. 이름 검색\n5. 종료\n\n");
        printf("번호를 선택하세요 : ");
        scanf("%d", &input);
        printf("\n");
        switch(input) {
            case 1:
                NameAscending();
                break;
            case 2:
                IdAscending();
                break;
            case 3:
                ScoreDescending();
                break;
            case 4:
                NameSearch();
                break;
            case 5:
                loop = false;
                break;
        }
    }

    return 0;
}