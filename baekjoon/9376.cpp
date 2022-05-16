#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 101;
const int INF = 1e9;
string board[MN];
int dp[MN][MN];
P path[MN][MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

struct node {
    int x, y, w;
    node(int x, int y, int w) x(x), y(y), w(w) {}
};

struct cmp {
    bool operator() (node a, node b) {
        return a.w > b.w;
    }
};

int main() {
    int T; cin >> T;
    while(T--) {
        int h, w; cin >> h >> w;
        fill(&dp[0][0], &dp[MN-1][MN], INF);
        memset(path, -1, sizeof(path));
        priority_queue<node, vector<node>, cmp> q1;
        priority_queue<node, vector<node>, cmp> q2;
        for(int i = 0; i < h; i++) {
            cin >> board[i];
            for(int j = 0; j < w; j++) {
                if(board[i][j] == '$') {
                    if(q1.empty())
                        q1.push(node(i, j, 0));
                    else
                        q2.push(node(i, j, 0));
                }
            }
        }
        P ans
        while(!q1.empty()) {
            node now = q1.front(); q1.pop();
            if(now.w > dp[now.x][now.y]) continue;
            for(int d= 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];
                if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if(board[nx][ny] == '*') continue;
                    if(board[nx][ny] == '#') {
                        if(dp[nx][ny] > now.w + 1) {
                            dp[nx][ny] = now.w + 1;
                            if(nx == 0 || nx == h-1 || ny == 0 || ny == w-1) {
                                ans1 = min(ans, now.w + 1);
                            }
                            else {
                                path[nx][ny] = make_pair(now.x, now.y);
                                q1.push(node(nx, ny, dp[nx][ny]));
                            }
                        }
                    }
                    else {
                        if(dp[nx][ny] > now.w) {
                            dp[nx][ny] = now.w;
                            path[nx][ny] = make_pair(now.x, now.y);
                            q1.push(node(nx, ny, dp[nx][ny]));
                        }
                    }
                }
            }
        }
    }
}