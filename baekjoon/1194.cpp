#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 51;
const int INF = 1e9;
int N, M;
int ans = INF;
string board[MN];
int dp[MN][MN][2][2][2][2][2][2];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

struct key {
    int a, b, c, d, e, f;
    key() {}
    key(int a, int b , int c, int d, int e, int f) : a(a), b(b), c(c), d(d), e(e), f(f) {}
};

void dfs(int nowX, int nowY, int cnt, key k) {
    if(dp[nowX][nowY][k.a][k.b][k.c][k.d][k.e][k.f] <= cnt) return;
    //cout << nowX << ' ' << nowY << endl;

    dp[nowX][nowY][k.a][k.b][k.c][k.d][k.e][k.f] = cnt;

    if(board[nowX][nowY] == '1') {
        ans = min(ans, cnt);
        return;
    }


    for(int d = 0; d < 4; d++) {
        int nx = nowX + dx[d];
        int ny = nowY + dy[d];
        key nk = key(k.a, k.b, k.c, k.d, k.e, k.f);
        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] == 'A' && k.a == 0) continue;
            if(board[nx][ny] == 'B' && k.b == 0) continue;
            if(board[nx][ny] == 'C' && k.c == 0) continue;
            if(board[nx][ny] == 'D' && k.d == 0) continue;
            if(board[nx][ny] == 'E' && k.e == 0) continue;
            if(board[nx][ny] == 'F' && k.f == 0) continue;
            switch(board[nx][ny]) {
                case 'a':
                    nk.a = 1;
                    break;
                case 'b':
                    nk.b = 1;
                    break;
                case 'c':
                    nk.c = 1;
                    break;
                case 'd':
                    nk.d = 1;
                    break;
                case 'e':
                    nk.e = 1;
                    break;
                case 'f':
                    nk.f = 1;
                    break;
            }
            dfs(nx, ny, cnt + 1, nk);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    P start, end;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
        for(int j = 0; j < M; j++) {
            if(board[i][j] == '0')
                start = make_pair(i, j);
        }
    }
    fill(&dp[0][0][0][0][0][0][0][0], &dp[N-1][M-1][1][1][1][1][1][2], INF);
    key k = key(0, 0, 0, 0, 0, 0);
    dfs(start.first, start.second, 0, k);

    if(ans == INF)
        cout << -1;
    else
        cout << ans;
}