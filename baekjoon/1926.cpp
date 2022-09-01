#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 501;

int board[MN][MN];
bool vst[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int N, M, cnt, width;

void bfs(int i, int j) {
    queue<P> q;
    q.push(make_pair(i, j));
    int tmp = 1;
    vst[i][j] = true;
    while(!q.empty()) {
        P now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(vst[nx][ny] || board[nx][ny] == 0) continue;
                tmp++;
                vst[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    width = max(width, tmp);
    cnt++;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    for(int i = 0; i< N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0 || vst[i][j])  continue;
            bfs(i, j);
        }
    }
    cout << cnt << '\n' << width;
}