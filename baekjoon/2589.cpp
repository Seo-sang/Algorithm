#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
const int MN = 51;
string board[MN];
bool visit[MN][MN];

struct edge {
    int x, y, cnt;
};

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> board[i];
    queue<edge> q;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 'W') continue;
            memset(visit, 0, sizeof(visit));
            visit[i][j] = true;
            q.push({i, j, 0});
            while(!q.empty()) {
                edge now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.x + dx[d];
                    int ny = now.y + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(visit[nx][ny] || board[nx][ny] == 'W') continue;
                        visit[nx][ny] = true;
                        q.push({nx, ny, now.cnt + 1});
                        ans = max(ans, now.cnt + 1);
                    }
                }
            }
        }
    }
    cout << ans;
}