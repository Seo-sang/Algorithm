#include <bits/stdc++.h>

using namespace std;
const int MN = 21;

int R, C, K;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int board[MN][MN], nxt[MN][MN];
bool wall[MN][MN], vst[MN][MN];

void bfs(int x, int y, int d) {
    memset(vst, 0, sizeof(vst));
    queue<P> q; q.push(make_pair(x, y));
    vst[x][y] = true;
    nxt[x][y] = 6;
    while(!q.empty()) {
        P now = q.front(); q.pop();
        int nx = now.first + dx[d];
        int ny = now.first + dy[d];
        if(!vst[nx][ny]) {
            nxt[nx][ny] = nxt[x][y] - 1;
        }
        
    }
}

void wind() {
    memset(nxt, 0, sizeof(nxt));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(1 <= board[i][j] && board[i][j] <= 4) {
                bfs(i, j, board[i][j]);
            }
        }
    }

    memcpy(board, nxt, sizeof(board));
}

int main() {
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> board[i][j];

    int W; cin >> W;
    while(W--) {
        int x, y, t; cin >> x >> y >> t;
        if(t == 0)
            wall[x-1][y] = true;
        else
            wall[x][y+1]= true;
        wall[x][y] = true;
    }
    int ans = 0;
    while(true) {
        wind();
    }
}