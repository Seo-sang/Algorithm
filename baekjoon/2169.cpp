#include <iostream>

using namespace std;

const int MN = 1001;
const int INF = 1e9;
int arr[MN][MN];
int dp[MN][MN][3];
int visit[MN][MN];

int dx[3] = {0, 0, 1};
int dy[3] = {1, -1, 0};
int N, M;

int dfs(int x, int y, int dir) {
    if(x == N && y == M) return arr[x][y];
    if(dp[x][y][dir] != -INF) return dp[x][y][dir];

    int ret = -INF;
    for(int d = 0; d < 3; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            ret = max(ret, dfs(nx, ny, d));
            visit[nx][ny] = false;
        }
    }
    dp[x][y][dir] = arr[x][y] + ret;
    return dp[x][y][dir];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    
    fill(&dp[0][0][0], &dp[N][M][4], -INF);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    visit[1][1] = 1;
    cout << dfs(1, 1, 0);

    /*
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    */
}