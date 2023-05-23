#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 51;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
string board[MN];
bool vst[MN][MN];
int N, M;

bool dfs(int x, int y, int px, int py, char c) {
    if(vst[x][y]) return true;
    vst[x][y] = true;

    bool ret = false;

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if(board[nx][ny] != c) continue;
            if(nx == px && ny == py) continue;
            ret |= dfs(nx, ny, x, y, c);
        }
    }
    vst[x][y] = false;
    return ret;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> board[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dfs(i, j, -1, -1, board[i][j])) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}