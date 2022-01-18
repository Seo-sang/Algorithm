#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MN = 1001;
int arr[MN][MN];
vector<int> g[MN];

bool visit[MN][MN];
int ans[MN][MN];

struct edge {
    int x, y, depth;
};

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(ans, -1, sizeof(ans));
    int N, M; cin >> N >> M;
    pair<int,int> start;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2)
                start = {i, j};
            if(arr[i][j] == 0)
                ans[i][j] = 0;
        }
    }
    queue<edge> q;
    visit[start.first][start.second] = true;
    ans[start.first][start.second] = 0;
    q.push({start.first, start.second, 0});
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(visit[nx][ny] || arr[nx][ny] == 0) continue;
                visit[nx][ny] = true;
                ans[nx][ny] = now.depth + 1;
                q.push({nx, ny, now.depth + 1});
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}