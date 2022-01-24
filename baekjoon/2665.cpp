#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int INF = 1e9;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

string board[MN];
int dp[MN][MN];

int main() {
    int N; cin >> N;
    fill(&dp[1][1], &dp[N][N + 1], INF);
    for(int i = 1; i <= N; i++) {
        cin >> board[i];
        board[i] = ' ' + board[i];
    }
    queue<pair<int,int> >q;
    
    q.push(make_pair(1, 1));
    dp[1][1] = 0;
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        int x = now.first;
        int y = now.second;
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                if(board[nx][ny] == '1') {
                    if(dp[nx][ny] > dp[x][y]) {
                        dp[nx][ny] = dp[x][y];
                        q.push(make_pair(nx, ny));
                    }
                }
                else {
                    if(dp[nx][ny] > dp[x][y] + 1) {
                        dp[nx][ny] = dp[x][y] + 1;
                        q.push(make_pair(nx ,ny));
                    }
                }
            }
        }
    }

    cout << dp[N][N];
}