#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

const int MN = 51;
int board[MN][MN];
bool visit[MN][MN];
int M, N, K; 

void dfs(int x, int y) {
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if(board[ny][nx] == 0 || visit[ny][nx]) continue;
            visit[ny][nx] = true;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(board, 0, sizeof(board));
        memset(visit, 0, sizeof(visit));
        cin >> M >> N >> K;
        while(K--) {
            int a, b; cin >> a >> b;
            board[b][a] = 1;
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(visit[i][j] || board[i][j] == 0) continue;
                visit[i][j] = true;
                ans++;
                dfs(j, i);
            }
        }

        cout <<ans << '\n';
    }
}