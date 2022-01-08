#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

struct edge {
    int x, y, cnt;
};

const int INF = 1e9;
const int MN = 101;
int N, M;
string maze[MN];
int visit[MN][MN];

int main() {
    int ans = INF;
    cin >> M >> N;
    for(int i = 0; i < N; i++)
        cin >> maze[i];
    fill(&visit[0][0], &visit[N-1][M], INF);
    if(N == 1 && M == 1) {
        cout << 0;
        return 0;
    }
    queue<edge> q;
    q.push({0, 0, 0});
    visit[0][0] = 0;
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(nx == N-1 && ny == M-1) {
                    ans = min(ans, now.cnt);
                    continue;
                }
                int cnt = now.cnt;
                if(maze[nx][ny] == '1')
                    cnt++;
                if(visit[nx][ny] <= cnt) continue;
                visit[nx][ny] = cnt;
                q.push({nx, ny, cnt});
            }
        }
    }
    cout << ans;
}