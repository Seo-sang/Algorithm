#include <iostream>
#include <queue>

using namespace std;

const int MN = 101;

string board[MN];
bool visit[MN][MN];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

struct edge {
    int x, y, w;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> board[i];
        board[i] = ' ' + board[i];
    }

    queue<edge> q;
    q.push({1, 1, 1});
    visit[1][1] = true;
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx > 0 && nx <= N && ny > 0 && ny <= M) {
                if(visit[nx][ny] || board[nx][ny] == '0') continue;
                visit[nx][ny] = true;
                if(nx == N && ny == M) {
                    cout << now.w + 1;
                    return 0;
                }
                q.push({nx, ny, now.w + 1});
            }
        }
    }
}