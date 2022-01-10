#include <iostream>
#include <cstring>

using namespace std;

const int MN = 51;
int board[MN][MN];
bool visit[MN][MN];

 int W, H; 
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};

void dfs(int x, int y) {
    for(int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < H && ny >= 0 && ny < W) {
            if(visit[nx][ny] || board[nx][ny] == 0) continue;
            visit[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    while(true) {
        memset(board, 0, sizeof(board));
        memset(visit, 0, sizeof(visit));
        cin >> W >> H;
        if(W == 0 && H == 0) break;

        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                cin >> board[i][j];

        int ans = 0;
        
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(visit[i][j] || board[i][j] == 0) continue;
                visit[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }
        cout << ans << '\n';
    }
}