#include <iostream>
#include <queue>

using namespace std;

const int MN = 101;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int board[MN][MN][MN];
bool visit[MN][MN][MN];

struct edge {
    int x, y, z, depth;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M, N, H; cin >> M >> N >> H;
    queue<edge> q;
    int cnt = 0;
    for(int k = 1; k <= H; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                cin >> board[k][i][j];
                if(board[k][i][j] == 1) {
                    q.push({i, j, k, 0});
                    visit[k][i][j] = true;
                }
                else if(board[k][i][j] == 0)
                    cnt++;
            }
        }
    }
    if(cnt == 0) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        for(int d = 0; d < 6; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            int nz = now.z + dz[d];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= M && nz >= 1 && nz <= H) {
                if(visit[nz][nx][ny] || board[nz][nx][ny] == -1) continue;
                visit[nz][nx][ny] = true;
                ans++;
                if(ans == cnt) {
                    cout << now.depth + 1;
                    return 0;
                }
                q.push({nx, ny, nz, now.depth + 1});
            }
        }
    }

    cout << -1;
    return 0;
}