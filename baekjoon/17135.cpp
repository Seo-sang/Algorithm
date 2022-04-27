#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 16;
int input[MN][MN], board[MN][MN];
bool vst[MN][MN];
int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};
int N, M, D;

struct node {
    int x, y, w;
};

P bfs(int x, int y) {
    queue<node> q;
    q.push({x, y, 0});
    memset(vst, 0, sizeof(vst));
    while(!q.empty()) {
        node now = q.front(); q.pop();
        for(int d = 0; d < 3; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];
            if(nx >= 0 && nx < x && ny >= 0 && ny < M) {
                if(vst[nx][ny]) continue;
                vst[nx][ny] = true;
                if(now.w + 1 <= D) {
                    if(board[nx][ny] == 1)
                        return make_pair(nx, ny);
                    q.push({nx, ny, now.w + 1});
                }
            }
        }
    }
    return make_pair(-1, -1);
}

int simul(int p1, int p2, int p3) {
    memcpy(board, input, sizeof(board));
    int ret = 0;
    for(int x = N; x > 0; x--) {
        set<P> s;
        s.insert(bfs(x, p1));
        s.insert(bfs(x, p2));
        s.insert(bfs(x, p3));
        for(auto it = s.begin(); it != s.end(); it++) {
            if(it->first != -1) {
                board[it->first][it->second] = 0;
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    cin >> N >> M >> D;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> input[i][j];

    int ans = 0;
    for(int i = 0; i < M - 2; i++)
        for(int j = i + 1; j < M - 1; j++)
            for(int k = j + 1; k < M; k++)
                ans = max(ans, simul(i, j, k));
    cout << ans;
}