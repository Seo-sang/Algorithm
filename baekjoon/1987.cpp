#include <iostream>
#include <queue>

using namespace std;

const int MN = 21;
string board[MN];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool alpha[27];
bool visit[MN][MN];

struct e {
    int x, y, total;
};
int R, C;
int ans;
void dfs(int x, int y, int total) {
    ans = max(ans, total);
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx > 0 && nx <= R && ny > 0 && ny <= C) {
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            char c = board[nx][ny];
            if(!alpha[c - 'A']) {
                alpha[c - 'A'] = true;
                dfs(nx, ny, total + 1);
                alpha[c - 'A'] = false;
            }
            visit[nx][ny] = false;
        }
    }
}

int main() {
    ans = 1;
    cin >> R >> C;
    for(int i = 1 ; i <= R; i++) {
        cin >> board[i];
        board[i] = ' ' + board[i];
    }
    visit[1][1] = true;
    alpha[board[1][1] - 'A'] = true;
    dfs(1, 1, 1);

    cout << ans;
}