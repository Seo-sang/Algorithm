#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 50;
int board[MN][MN];
int idx[MN][MN];
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cx[4] = {0, 1, 0, -1};
int cy[4] = {-1, 0, 1, 0};

int main() {
    cin >> N >> M;
    vector<int> ball(N * N);
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
            cin >> board[i][j];
            ball[idx[i][j]] = board[i][j];
        }
    }

    while(M--) {
        int d, s; cin >> d >> s; d--;
        int x = N / 2, y = N / 2;
        while(s--) {
            
        }
    }
}