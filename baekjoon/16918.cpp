#include <bits/stdc++.h>

using namespace std;

const int MN = 201;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int now[MN][MN], nxt[MN][MN];
int R, C, N;

void print() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(now[i][j] == 0) cout << '.';
            else cout << 'O';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C >> N;

    for(int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < C; j++) {
            if(str[j] == 'O') now[i][j] = 3;
        }
    }
    int cnt = 1;
    while(cnt < N) {
        cnt++;
        memcpy(nxt, now, sizeof(nxt));
        if(cnt % 2) {
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    if(now[i][j] == cnt) {
                        nxt[i][j] = 0;
                        for(int d = 0; d < 4; d++) {
                            int ni = i + dx[d];
                            int nj = j + dy[d];
                            if(ni >= 0 && ni < R && nj >= 0 && nj < C) {
                                nxt[ni][nj] = 0;
                            }
                        }
                    }
                }
            }
        }
        else {
            for(int i = 0; i < R; i++) {
                for(int j = 0; j < C; j++) {
                    if(now[i][j] == 0) nxt[i][j] = cnt + 3;
                }
            }
        }
        memcpy(now, nxt, sizeof(now));
    }

    print();
}