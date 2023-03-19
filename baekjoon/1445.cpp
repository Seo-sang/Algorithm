#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 51;
const int INF = 1e9;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

string board[MN];
P dp[MN][MN];
bool trash[MN][MN];

struct node {
    int x, y, pass, side;
    node(int x, int y, int pass, int side) : x(x), y(y), pass(pass), side(side) {};
};

int main() {
    int N, M; cin >> N >> M;
    P start, end;
    for(int i = 0; i < N; i++)
        cin >> board[i];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dp[i][j] = make_pair(INF, INF);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 'S') {
                start = make_pair(i, j);
                continue;
            }
            if(board[i][j] == 'F') {
                end = make_pair(i, j);
                continue;
            }
            if(board[i][j] == 'g') continue;
            bool cnt = false;
            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M)
                    if(board[nx][ny] == 'g') cnt = true;
            }
            trash[i][j] = cnt;
        }
    }

    queue<node> q;
    dp[start.first][start.second] = make_pair(0, 0);
    q.push(node(start.first, start.second, 0, 0));
    while(!q.empty()) {
        node now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                int npass = now.pass;
                int nside = now.side + trash[nx][ny];
                if(board[nx][ny] == 'g') npass++;

                if(npass < dp[nx][ny].first) {
                    dp[nx][ny] = make_pair(npass, nside);
                    q.push(node(nx, ny, npass, nside));
                }
                else if(npass == dp[nx][ny].first) {
                    if(nside < dp[nx][ny].second) {
                        dp[nx][ny] = make_pair(npass, nside);
                        q.push(node(nx, ny, npass, nside));
                    }
                }
            }
        }
    }

    cout << dp[end.first][end.second].first << ' ' << dp[end.first][end.second].second;
}