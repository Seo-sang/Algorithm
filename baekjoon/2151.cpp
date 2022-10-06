#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int INF = 1e9;
string board[MN];
int dp[MN][MN][2];
//int dp[MN][MN][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

struct node {
    int x, y, d, cnt;
    node(int x, int y, int d, int cnt) : x(x), y(y), d(d), cnt(cnt) {}
};

bool can(int x, int y) {
    return (x >= 0 && x < N && y >=0 && y < N);
}

int main() {
    cin >> N;
    fill(&dp[0][0][0], &dp[N-1][N-1][2], INF);
    queue<node> q;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
        for(int j = 0; j < N; j++) {
            if(board[i][j] == '#' && q.empty()) {
                for(int d = 0; d < 4; d++) {
                    q.push(node(i, j, d, 0));
                }
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }
        }
    }
    int ans = INF;
    while(!q.empty()) {
        node now = q.front(); q.pop();
        //cout << now.x << ' ' << now.y << ' ' << now.cnt << endl;
        int x = now.x + dx[now.d];
        int y = now.y + dy[now.d];
        
        while(can(x, y) && board[x][y] == '.') {
            x = x + dx[now.d];
            y = y + dy[now.d];
        }
        if(!can(x, y)) continue;
        if(board[x][y] == '#') {
            if(dp[x][y][0] > now.cnt)
                dp[x][y][0] = now.cnt;
            if(dp[x][y][1] > now.cnt)
                dp[x][y][1] = now.cnt;
            ans = min(ans, min(dp[x][y][0], dp[x][y][1]));
            continue;
        }
        if(board[x][y] == '!') {
            if(dp[x][y][0] > now.cnt + 1) {
                dp[x][y][0] = now.cnt + 1;
                switch(now.d) {
                    case 0:
                        q.push(node(x, y, 1, now.cnt + 1));
                        break;
                    case 1:
                        q.push(node(x, y, 0, now.cnt + 1));
                        break;
                    case 2:
                        q.push(node(x, y, 3, now.cnt + 1));
                        break;
                    case 3:
                        q.push(node(x, y, 2, now.cnt + 1));
                        break;
                }
            }
            if(dp[x][y][1] > now.cnt + 1) {
                dp[x][y][1] = now.cnt + 1;
                switch(now.d) {
                    case 0:
                        q.push(node(x, y, 3, now.cnt + 1));
                        break;
                    case 1:
                        q.push(node(x, y, 2, now.cnt + 1));
                        break;
                    case 2:
                        q.push(node(x, y, 1, now.cnt + 1));
                        break;
                    case 3:
                        q.push(node(x, y, 0, now.cnt + 1));
                        break;
                }
            }
            q.push(node(x, y, now.d, now.cnt));
        }
    }
    cout << ans;
}