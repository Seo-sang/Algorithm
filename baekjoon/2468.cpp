#include <iostream>
#include <cstring>

using namespace std;

const int MN = 101;
int board[MN][MN];
bool visit[MN][MN];
int N; 
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void dfs(int x, int y, int h) {
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx > 0 && nx <= N && ny > 0 && ny <= N) {
            if(visit[nx][ny] || board[nx][ny] <= h) continue;
            visit[nx][ny] = true;
            dfs(nx, ny, h);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    int maxh = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
            maxh = max(maxh, board[i][j]);
        }
    }
    int cnt, ans = 0;
    for(int h = 0; h < maxh; h++) {
        memset(visit, 0, sizeof(visit));
        cnt = 0;
        for(int i = 1;  i<= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(board[i][j] <= h || visit[i][j]) continue;
                visit[i][j] = true;
                cnt++;
                dfs(i, j, h);
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}