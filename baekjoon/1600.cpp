#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MN = 201;
const int MK = 31;
const int INF = 1e9;

int hx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool visit[MN][MN][MK];
int board[MN][MN];

struct edge {
    int x, y, depth, cnt;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K; cin >> K;
    int W, H; cin >> W >> H;

    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
            cin >> board[i][j];

    if(W == 1 && H == 1) {
        cout << 0;
        return 0;
    }

    visit[0][0][0] = true;
    queue<edge> q;
    q.push({0, 0, 0, 0});

    while(!q.empty()) {
        edge now = q.front(); q.pop();
        //cout << "start : " << now.x << ' ' << now.y << endl;
        if(now.cnt < K) {
            for(int d = 0; d < 8; d++) {
                int nx = now.x + hx[d];
                int ny = now.y + hy[d];
                //cout << nx << ' ' << ny << endl;
                if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if(visit[nx][ny][now.cnt + 1] || board[nx][ny] == 1) continue;
                    visit[nx][ny][now.cnt + 1] = true;
                    if(nx == H - 1 && ny == W - 1) {
                        cout << now.depth + 1;
                        return 0;
                    }
                    q.push({nx, ny, now.depth + 1, now.cnt + 1});
                }
            }
        }
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            //cout << nx << ' ' << ny << endl;
            if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if(visit[nx][ny][now.cnt] || board[nx][ny] == 1) continue;
                visit[nx][ny][now.cnt] = true;
                if(nx == H - 1 && ny == W - 1) {
                    cout << now.depth + 1;
                    return 0;
                }
                q.push({nx, ny, now.depth + 1, now.cnt});
            }
        }
        
    }
    cout << -1;
}