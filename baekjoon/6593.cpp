#include <bits/stdc++.h>

using namespace std;
const int MN = 31;
const int INF = 1e9;
string board[MN][MN];
bool vst[MN][MN][MN];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct pos {
    int x, y, z, d;
    pos(int x, int y, int z, int d) : x(x), y(y), z(z), d(d) {}
};

int main() {
    int L, R, C;
    while(true) {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) break;
        memset(vst, 0, sizeof(vst));
        queue<pos> q;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                cin >> board[i][j];
                for(int k = 0; k < C; k++) {
                    if(board[i][j][k] == 'S') {
                        q.push(pos(i, j, k, 0));
                        vst[i][j][k] = true;
                    }
                }
            }
        }
        int ans = INF;
        while(!q.empty() && ans == INF) {
            pos now = q.front(); q.pop();
            for(int d = 0; d < 6; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];
                int nz = now.z + dz[d];
                if(nx >= 0 && nx < L && ny >= 0 && ny < R && nz >= 0 && nz < C) {
                    if(vst[nx][ny][nz] || board[nx][ny][nz] == '#') continue;
                    vst[nx][ny][nz] = true;
                    if(board[nx][ny][nz] == 'E') {
                        ans = now.d + 1;
                        break;
                    }
                    q.push(pos(nx, ny, nz, now.d + 1));
                }
            }
        }
        if(ans == INF) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
        
    }

}