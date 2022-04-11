#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int INF = 1e9;
string board[MN];
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dp[MN][MN][4];
bool vst[MN][MN][4];
bool cycle = false;

int dfs(int x, int y, int d) {
    int &ret = dp[x][y][d];
    if(ret != -1) return ret;
    ret = 0;
    int nx = x + dx[d] * (board[x][y] - '0');
    int ny = y + dy[d] * (board[x][y] - '0');
    if(nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 'H') {
        for(int nd = 0; nd < 4; nd++) {
            if(vst[nx][ny][nd]) {
                cycle = true;
                continue;
            }
            vst[nx][ny][nd] = true;
            ret = max(ret, dfs(nx, ny, nd) + 1);
            vst[nx][ny][nd] = false;
        }
        return ret;
    }
    else return 0;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> board[i];

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int d = 0; d < 4; d++) {
        vst[0][0][d] = true;
        ans = max(ans, dfs(0, 0, d) + 1);
        vst[0][0][d] = false;
    }

    if(cycle)
        cout << -1;
    else
        cout << ans;
}