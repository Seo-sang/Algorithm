#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 101;
const int INF = 1e9;

string board[MN];
int mirror[MN][MN][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int W, H;
struct edge {
    int x, y, cnt, d;
    edge(int a, int b, int c, int f) : x(a), y(b), cnt(c), d(f) {}
};

int main() {
    cin >> W >> H;
    P start = make_pair(-1, -1), end = make_pair(-1, -1);
    fill(&mirror[0][0][0], &mirror[H-1][W-1][5], INF);
    for(int i = 0; i < H; i++) {
        cin >> board[i];
        for(int j = 0; j < W; j++) {
            if(board[i][j] == 'C' && start.first == -1)
                start = make_pair(i, j);
            else if(board[i][j] == 'C' && start.first != -1)
                end = make_pair(i, j);
        }
    }
    queue<edge> q;
    q.push(edge(start.first, start.second, 0, 0));
    q.push(edge(start.first, start.second, 0, 1));
    q.push(edge(start.first, start.second, 0, 2));
    q.push(edge(start.first, start.second, 0, 3));
    mirror[start.first][start.second][0] = 0;
    mirror[start.first][start.second][1] = 0;
    mirror[start.first][start.second][2] = 0;
    mirror[start.first][start.second][3] = 0;

    while(!q.empty()) {
        edge now = q.front(); q.pop();
        if(mirror[now.x][now.y][now.d] < now.cnt) continue;
        //같은 방향
        int nx = now.x + dx[now.d];
        int ny = now.y + dy[now.d];
        if(nx >= 0 && nx < H && ny >= 0 && ny < W && board[nx][ny] != '*') {
            if(mirror[nx][ny][now.d] > now.cnt) {
                mirror[nx][ny][now.d] = now.cnt;
                q.push(edge(nx, ny, now.cnt, now.d));
            }
        }

        int nd = (now.d + 3) % 4;
        nx = now.x + dx[nd];
        ny = now.y + dy[nd];
        if(nx >= 0 && nx < H && ny >= 0 && ny < W && board[nx][ny] != '*') {
            if(mirror[nx][ny][nd] > now.cnt + 1) {
                mirror[nx][ny][nd] = now.cnt + 1;
                q.push(edge(nx, ny, now.cnt + 1, nd));
            }
        }

        nd = (now.d + 1) % 4;
        nx = now.x + dx[nd];
        ny = now.y + dy[nd];
        if(nx >= 0 && nx < H && ny >= 0 && ny < W && board[nx][ny] != '*') {
            if(mirror[nx][ny][nd] > now.cnt + 1) {
                mirror[nx][ny][nd] = now.cnt + 1;
                q.push(edge(nx, ny, now.cnt + 1, nd));
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 4; i++)
        ans = min(ans, mirror[end.first][end.second][i]);
    cout << ans;
}