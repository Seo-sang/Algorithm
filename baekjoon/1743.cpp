#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 101;
bool board[MN][MN];
bool vst[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main() {
    int N, M, K; cin >> N >> M >> K;
    while(K--) {
        int r, c; cin >> r >> c;
        board[r-1][c-1] = true;
    }
    int ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!board[i][j] || vst[i][j]) continue;
            int cnt = 1;
            vst[i][j] = true;
            queue<P> q; q.push({i, j});
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(!board[nx][ny] || vst[nx][ny]) continue;
                        vst[nx][ny] = true;
                        q.push({nx, ny});
                        cnt++;
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans;
}