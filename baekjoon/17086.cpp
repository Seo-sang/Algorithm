#include <bits/stdc++.h>
using namespace std;

const int MN = 51;
const int INF = 1e9;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {0, 1, -1, 1, -1, 0, 1, -1};

int board[MN][MN];
bool vst[MN][MN];
struct node {
    int x, y, d;
    node(int x, int y, int d) : x(x), y(y), d(d) {}
};

int main() {
    int N, M; cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    int ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j]) continue;
            memset(vst, 0, sizeof(vst));
            vst[i][j] = true;
            int cnt = INF;
            queue<node> q; q.push(node(i, j, 0));
            while(!q.empty()) {
                node now = q.front(); q.pop();
                for(int d = 0; d < 8; d++) {
                    int nx = now.x + dx[d];
                    int ny = now.y + dy[d];
                    int nd = now.d + 1;
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(vst[nx][ny]) continue;
                        vst[nx][ny] = true;
                        if(board[nx][ny] == 1) cnt = min(cnt, nd);
                        else q.push(node(nx, ny, nd));
                    }
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans;
}