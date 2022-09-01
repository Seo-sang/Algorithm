#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
const int INF = 1e9;
int board[MN][MN][11][2];
string arr[MN];
int dx[5] = {1, 0, 0, -1, 0};
int dy[5] = {0, 1, -1, 0, 0};

struct edge {
    int x, y, cnt, t;
};

int main() {
    int N, M, K; cin >> N >> M >> K;
    fill(&board[0][0][0][0], &board[N-1][M-1][10][2], INF);
    board[0][0][0][0] = 1;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    queue<edge> q;
    q.push({0, 0, 0, 0});
    while(!q.empty()) {
        edge now = q.front(); q.pop();
        for(int d = 0; d < 5; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            int ncnt = now.cnt;
            int nt = (now.t + 1) % 2;
            if(d == 4) {
                if(board[nx][ny][ncnt][nt] > board[now.x][now.y][now.cnt][now.t] + 1) {
                    board[nx][ny][ncnt][nt] = board[now.x][now.y][now.cnt][now.t] + 1;
                    q.push({nx, ny, ncnt, nt});
                    continue;
                }
            }
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(arr[nx][ny] == '1') {
                    if(nt == 0) continue;
                    ncnt++;
                }
                if(ncnt <= K && (board[nx][ny][ncnt][nt] > board[now.x][now.y][now.cnt][now.t] + 1)) {
                    board[nx][ny][ncnt][nt] = board[now.x][now.y][now.cnt][now.t] + 1;
                    q.push({nx, ny, ncnt, nt});
                }
            }
        }
    }
    
    int ans = INF;
    for(int i = 0; i < 11; i++) {
        ans = min(ans, board[N-1][M-1][i][0]);
        ans = min(ans, board[N-1][M-1][i][1]);
    }
    
    if(ans == INF) cout << -1;
    else cout << ans;
}
