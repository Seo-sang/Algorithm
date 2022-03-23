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

void destroy(int x, int y) {
    switch(ball[idx[x][y]]) {
        case 1:
            ball1++;
            break;
        case 2:
            ball2++;
            break;
        case 3:
            ball3++;
            break;
    }
    ball[idx[x][y]] = 0;
}

int main() {
    cin >> N >> M;
    ball.resize(N * N);
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
        while(s--) {
            x += dx[d], y += dy[d];
            destroy(x, y);
        }
    }
}