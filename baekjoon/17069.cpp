#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 33;
int board[MN][MN];
ll dp[3][MN][MN];

int N;

ll dfs(int dir, int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= N) return 0;
    if(dir == 0)
        if(board[x][y]) return 0;
    if(dir == 1)
        if(board[x][y]) return 0;
    if(dir == 2)
        if(board[x][y] || board[x - 1][y] || board[x][y - 1]) return 0;

    if((x == N - 1) && (y == N - 1)) return 1;

    if(dp[dir][x][y] != -1) return dp[dir][x][y];

    ll &ret = dp[dir][x][y];
    ret = 0;

    switch(dir) {
        case 0: //오른쪽
            ret += dfs(0, x, y + 1);
            ret += dfs(2, x + 1, y + 1);
            break;
        case 1: //아래
            ret += dfs(1, x + 1, y);
            ret += dfs(2, x + 1, y + 1);
            break;
        case 2: //대각선
            ret += dfs(0, x, y + 1);
            ret += dfs(1, x + 1, y);
            ret += dfs(2, x + 1, y + 1);
            break;
    }

    return ret;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> board[i][j];

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0, 1);

}