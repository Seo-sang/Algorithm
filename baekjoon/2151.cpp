#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
const int INF = 1e9;
string board[MN];
bool vst[MN][MN][4];
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
    //fill(&dp[0][0], &dp[N-1][N], INF);
    queue<node> q;
    for(int i = 0; i < N; i++) {
        cin >> board[i];
        for(int j = 0; j < N; j++) {
            if(board[i][j] == '#' && q.empty()) {
                for(int d = 0; d < 4; d++) {
                    q.push(node(i, j, d, 0));
                    vst[i][j][d] = true;
                }
                //dp[i][j] = 0;
            }
        }
    }
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
        if(board[x][y] == '#' && !vst[x][y][now.d]) {
            cout << now.cnt;
            return 0;
        }
        if(board[x][y] == '*' || vst[x][y][now.d]) continue;
        //dp[x][y] = now.cnt + 1;
        q.push(node(x, y, (now.d + 3) % 4, now.cnt + 1));
        q.push(node(x, y, (now.d + 1) % 4, now.cnt + 1));
    }
}