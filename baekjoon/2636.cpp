#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 101;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int N, M; 
void air(int x, int y, int board[MN][MN]) {
    board[x][y] = -1;
    queue<pair<int,int>> q;
    q.push({x, y});
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if(board[nx][ny] == 0) {
                    board[nx][ny] = -1;
                    q.push({nx, ny});
                }
            }

        }
    }
}

int main() {
    int board[MN][MN];
    int nxt[MN][MN];
    memset(board, 0, sizeof(board));
    memset(nxt, 0, sizeof(nxt));
    cin >> N >> M;

    int time = 0;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j]) cnt++;
        }
    }
    if(cnt == 0) {
        cout << 0 << '\n' << 0;
        return 0;
    }
    ans = cnt;
    air(0, 0, board);
    memcpy(nxt, board, sizeof(nxt));
    while(true) {
        cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] == 1) {
                    int blank = 0;
                    for(int d = 0; d <4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < M)
                            if(board[nx][ny] == -1) blank++;
    
                    }
                    if(blank != 0) {
                        nxt[i][j] = -1;
                        for(int d = 0; d <4; d++) {
                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                                if(nxt[nx][ny] == 0) {
                                    air(nx, ny, nxt);
                                }
                            }
                        }
                    }
                    else
                        cnt++;
                }
            }
        }
        time++;
        if(!cnt)
            break;
        ans = cnt;
        memcpy(board, nxt, sizeof(board));
    }
    cout << time << '\n' << ans;
}