#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

const int MN = 21;
const int INF = 1e9;
string board[MN];
map<pii, int> m;
int dist[MN][MN][1 << 10];

struct node {
    int x, y, vst, cnt;
    node(int x, int y, int vst, int cnt) : x(x), y(y), vst(vst), cnt(cnt) {}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int W, H;
    while(true) {
        cin >> W >> H;
        int idx = 0;
        pii start;
        m.clear();
        if(!(W || H)) break;
        for(int i = 0; i < H; i++) {
            cin >> board[i];
            for(int j = 0; j < W; j++) {
                if(board[i][j] == 'o') start = pii(i, j);
                if(board[i][j] == '*') m[pii(i,j)] = idx++;
            }
        }
        queue<node> q; q.push(node(start.first, start.second, 0, 0));
        fill(&dist[0][0][0], &dist[H-1][W-1][(1 << 10) - 1], INF);
        dist[start.first][start.second][0] = 0;
        int ans = INF;
        while(!q.empty()) {
            node now = q.front(); q.pop();
            if(now.vst == ((1 << idx) - 1)) ans = min(ans, now.cnt);
            if(dist[now.x][now.y][now.vst] < now.cnt) continue;
            for(int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];
                int nvst = now.vst;
                int ncnt = now.cnt + 1;
                if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if(board[nx][ny] == 'x') continue;
                    if(board[nx][ny] == '*') {
                        int pos = m[pii(nx, ny)];
                        nvst |= (1 << pos);
                    }
                    if(dist[nx][ny][nvst] > ncnt) {
                        dist[nx][ny][nvst] = ncnt;
                        q.push(node(nx, ny, nvst, ncnt));
                    }
                }
            }
        }
        if(ans == INF) cout << "-1\n";
        else cout << ans << '\n';
    }
}