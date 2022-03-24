#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 50;
int board[MN][MN];
int idx[MN][MN];
int N, M;
int ball1, ball2, ball3;
vector<int> ball;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cx[4] = {0, 1, 0, -1};
int cy[4] = {-1, 0, 1, 0};

void destroy(int color, int n) {
    switch(color) {
        case 1:
            ball1 += n;
            break;
        case 2:
            ball2 += n;
            break;
        case 3:
            ball3 += n;
            break;
    }
}

//빈 칸 없애는 함수
void compact() {
    vector<int> rst;
    rst.push_back(0);
    for(int i = 1; i < ball.size(); i++)
        if(ball[i] != 0)
            rst.push_back(ball[i]);

    while(rst.size() < N * N)
        rst.push_back(0);
    ball = rst;
}

//폭발하는 함수
void explode() {
    vector<int> rst;
    while(true) {
        rst.clear();
        rst.push_back(0);
        bool chk = false;
        for(int i = 1; i < ball.size(); i++) {
            if(ball[i] == 0) continue;
            if(i + 3 < ball.size()) {
                if(ball[i] == ball[i+1] && ball[i+1] == ball[i+2] && ball[i+2] == ball[i+3]) {
                    int j = i + 4;
                    while(j < ball.size() && ball[j] == ball[i]) j++;
                    j--;
                    destroy(ball[i], j - i  + 1);
                    i = j;
                    chk = true;
                }
                else
                    rst.push_back(ball[i]);
            }
            else
                rst.push_back(ball[i]);
        }
        ball = rst;
        if(!chk) break;
    }
    while(ball.size() < N * N) ball.push_back(0);
}

void change() {
    vector<int> rst;
    rst.push_back(0);
    for(int i = 1; i < ball.size(); i++) {
        if(ball[i] == 0) continue;
        int j = i + 1;
        while(j < ball.size() && ball[i] == ball[j]) j++;
        j--;
        rst.push_back(j - i + 1);
        if(rst.size() == N * N) break;
        rst.push_back(ball[i]);
        if(rst.size() == N * N) break;
        i = j;
    }

    while(rst.size() < N * N)
        rst.push_back(0);
    ball = rst;
}

int main() {
    cin >> N >> M;
    ball.resize(N * N, 0);
    
    int num = 0, c = 0;
    P pos = make_pair(N / 2, N / 2);
    for(int len = 1; len < 50; len++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < len; j++) {
                idx[pos.first][pos.second] = num++;
                pos.first += cx[c];
                pos.second += cy[c];
                if(num == N * N) break;
            }
            if(num == N * N) break;
            c = (c + 1) % 4;
        }
        if(num == N * N) break;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int a; cin >> a;
            ball[idx[i][j]] = a;
        }
    }
    while(M--) {
        int d, s; cin >> d >> s; d--;
        int x = N / 2, y = N / 2;

        //한 방향으로 구슬 파괴
        while(s--) {
            x += dx[d], y += dy[d];
            if(idx[x][y] < ball.size())
                ball[idx[x][y]] = 0;
        }
        //빈칸으로 이동
        compact();

        //구슬 폭발
        explode();

        //변경
        change();
    }

    cout << ball1 + (2 * ball2) + (3 * ball3);
}