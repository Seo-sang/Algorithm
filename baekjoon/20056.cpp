#include <bits/stdc++.h>

using namespace std;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MN = 51;
int N, M, K;
struct node {
    int m, s, cnt;
};
node board[MN][MN][8];
node nxt[MN][MN][8];

void occur() {
    memset(nxt, 0, sizeof(nxt));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int d = 0; d < 8; d++) {
                node now = board[i][j][d];
                if(now.cnt < 1) continue;
                int nx = (i + (now.s * dx[d]) + (N * now.s)) % N;
                int ny = (j + (now.s * dy[d]) + (N * now.s)) % N;
                nxt[nx][ny][d].m += now.m;
                nxt[nx][ny][d].s += now.s;
                nxt[nx][ny][d].cnt++;
            }
        }
    }
    
    memset(board, 0, sizeof(board));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int msum = 0, ssum = 0, total = 0;
            bool odd = false, even = false;
            for(int d = 0; d < 8; d++) {
                node now = nxt[i][j][d];
                if(now.cnt > 0) { 
                    total += now.cnt;
                    msum += now.m;
                    ssum += now.s;
                    (d % 2) ? (odd = true) : (even = true);
                }
            }
            if(total > 1) {
                if(msum / 5 > 0) {
                    if(odd && even) {
                        for(int d = 1; d < 8; d += 2) {
                            board[i][j][d].m = msum / 5;
                            board[i][j][d].s = ssum / total;
                            board[i][j][d].cnt = 1;
                        }
                    }
                    else {
                        for(int d = 0; d < 8; d += 2) {
                            board[i][j][d].m = msum / 5;
                            board[i][j][d].s = ssum / total;
                            board[i][j][d].cnt = 1;
                        }
                    }
                }
            }
            else {
                for(int d = 0; d < 8; d++)
                    board[i][j][d] = nxt[i][j][d];
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    while(M--) {
        int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
        board[r-1][c-1][d] = {m, s, 1};
    }
    while(K--) {
        occur();
    }
    int ans = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int d = 0; d < 8; d++)
                ans += board[i][j][d].m;

    cout << ans;
}