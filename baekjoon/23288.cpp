#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 21;
int board[MN][MN];
bool vst[MN][MN];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dice[6] = {1, 2, 3, 4, 5, 6};
int N, M, K;

void east() {
    int nxt[6];
    nxt[0] = dice[3], nxt[1] = dice[1];
    nxt[2] = dice[0], nxt[3] = dice[5];
    nxt[4] = dice[4], nxt[5] = dice[2];
    memcpy(dice, nxt, sizeof(dice));
}

void west() {
    int nxt[6];
    nxt[0] = dice[2], nxt[1] = dice[1];
    nxt[2] = dice[5], nxt[3] = dice[0];
    nxt[4] = dice[4], nxt[5] = dice[3];
    memcpy(dice, nxt, sizeof(dice));
}

void north() {
    int nxt[6];
    nxt[0] = dice[4], nxt[1] = dice[0];
    nxt[2] = dice[2], nxt[3] = dice[3];
    nxt[4] = dice[5], nxt[5] = dice[1];
    memcpy(dice, nxt, sizeof(dice));
}

void south() {
    int nxt[6];
    nxt[0] = dice[1], nxt[1] = dice[5];
    nxt[2] = dice[2], nxt[3] = dice[3];
    nxt[4] = dice[0], nxt[5] = dice[4];
    memcpy(dice, nxt, sizeof(dice));
}

int bfs(int x, int y, int num) {
    memset(vst, 0, sizeof(vst));
    queue<P> q;
    int cnt = 1;
    q.push(make_pair(x, y));
    vst[x][y] = true;
    while(!q.empty()) {
        P now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(vst[nx][ny] || board[nx][ny] != num) continue;
                vst[nx][ny] = true;
                cnt++;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return num * cnt;
}

int main() {
    cin >> N >> M >> K;
    for(int i= 0; i < N; i++)
        for(int j= 0; j < M; j++)
            cin >> board[i][j];

    int x =0, y = 0;
    int d = 0;
    int ans = 0;
    while(K--) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) {
            nx = x - dx[d];
            ny = y - dy[d];
            d = (d + 2) % 4;
        }
        ans += bfs(nx, ny, board[nx][ny]);
        switch(d) {
            case 0:
                east();
                break;
            case 1:
                south();
                break;
            case 2:
                west();
                break;
            case 3:
                north();
                break;
        }
        x = nx, y = ny;
        if(dice[5] > board[nx][ny]) d = (d + 1) % 4;
        else if(dice[5] < board[nx][ny]) d = (d + 3) % 4;
    }

    cout << ans;
}