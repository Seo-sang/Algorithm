#include <iostream>
#include <queue>

using namespace std;

const int MN = 1001;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int board[MN][MN];
bool visit[MN][MN];

struct edge {
    int x, y, depth;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M, N; cin >> M >> N;
    queue<edge> q;
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                q.push({i, j, 0});
                visit[i][j] = true;
            }
            else if(board[i][j] == 0)
                cnt++;
        }
    }
    if(cnt == 0) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                if(visit[nx][ny] || board[nx][ny] == -1) continue;
                visit[nx][ny] = true;
                ans++;
                if(ans == cnt) {
                    cout << now.depth + 1;
                    return 0;
                }
                q.push({nx, ny, now.depth + 1});
            }
        }
    }

    cout << -1;
    return 0;
}