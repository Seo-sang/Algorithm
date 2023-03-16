#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 33;
int board[MN][MN];
ll dp[3][MN][MN][MN][MN];

int N;

ll dfs(int dir, int x1, int y1, int x2, int y2) {
    if(x1 < 0 || x1 >= N || y1 < 0 || y1 >= N) return 0;
    if(x2 < 0 || x2 >= N || y2 < 0 || y2 >= N) return 0;
    if(dir == 0)
        if(board[x2][y2]) return 0;
    if(dir == 1)
        if(board[x2][y2]) return 0;
    if(dir == 2)
        if(board[x2][y2] || board[x2 - 1][y2] || board[x2][y2 - 1]) return 0;

    if((x1 == N - 1) && (y1 == N - 1)) return 1;
    if((x2 == N - 1) && (y2 == N - 1)) return 1;

    if(dp[dir][x1][y1][x2][y2] != -1) return dp[dir][x1][y1][x2][y2];

    ll &ret = dp[dir][x1][y1][x2][y2];
    ret = 0;

    switch(dir) {
        case 0: //오른쪽
            ret += dfs(0, x1, y1 + 1, x2, y2 + 1);
            ret += dfs(2, x1, y1 + 1, x2 + 1, y2 + 1);
            break;
        case 1: //아래
            ret += dfs(1, x1 + 1, y1, x2 + 1, y2);
            ret += dfs(2, x1 + 1, y1, x2 + 1, y2 + 1);
            break;
        case 2: //대각선
            ret += dfs(0, x1 + 1, y1 + 1, x2, y2 + 1);
            ret += dfs(1, x1 + 1, y1 + 1, x2 + 1, y2);
            ret += dfs(2, x1 + 1, y1 + 1, x2 + 1, y2 + 1);
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

    cout << dfs(0, 0, 0, 0, 1);

}