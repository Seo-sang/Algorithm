#include <iostream>

using namespace std;

const int MN = 1001;
const int INF = 1e9;
int arr[MN][MN];
int dp[MN][MN];
int visit[MN][MN];

int dx[3] = {0, 0, 1};
int dy[3] = {1, -1, 0};
int N, M;

int dfs(int x, int y) {
    if(x == N && y == M) return arr[x][y];
    if(dp[x][y]) return dp[x][y];
    int ret = -INF;
    if(y + 1 >= 1 && y + 1 <= M) {
        if(!visit[x][y+1]) {
            visit[x][y+1] = 1;
            ret = max(ret, )
        }
    }
    for(int d = 0; d < 3; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            dp[nx][ny] = max(dp[nx][ny], dp[x][y] + arr[nx][ny]);
            dfs(nx, ny);
            visit[nx][ny] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    visit[1][1] = 1;
    dfs(1, 1);

    cout << dp[N][M];
}