#include <iostream>

using namespace std;

int board[17][17];
int N;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int ans;
void dfs(pair<int,int> head, pair<int,int> tail, int dir) {
    for(int d = 0; d < 3; d++) {
        if(dir == 0 && d == 1) continue;
        if(dir == 1 && d == 0) continue;
        int nx = head.first + dx[d];
        int ny = head.second + dy[d];

        if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
        if(board[nx][ny] == 1) continue;
        if(d == 2) {
            if(board[nx-1][ny] || board[nx][ny-1]) continue;
        }

        if(nx == N && ny == N) {
            ans++;
            return;
        }
        dfs({nx, ny}, head, d);
    }
}

//가로 0, 세로 1, 대각선 2
int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> board[i][j];

    pair<int,int> head = {1, 2};
    pair<int,int> tail = {1, 1};
    int dir = 0;
    dfs(head, tail, dir);

    cout << ans;
}