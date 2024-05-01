#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 2001;
const int INF = 1e9;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

string board[MN];
int idx = 1;
int N, M;
int cnt[MN][MN], vst[MN * MN];
set<int> g[MN * MN];
int ans[MN * MN];


int dfs(int now, int prev, int order) {
    vst[now] = order;
    ans[now] = order;

    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        if(!vst[nxt]) ans[now] = min(ans[now], dfs(nxt, now, order + 1));
        else ans[now] = min(ans[now], vst[nxt]);
    }


    return ans[now];
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> board[i];

    queue<pii> q;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(cnt[i][j]) continue;
            queue<pii> q;
            q.push(pii(i, j));
            cnt[i][j] = idx;
            while(!q.empty()) {
                pii now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(cnt[nx][ny] || board[i][j] != board[nx][ny]) continue;
                        cnt[nx][ny] = idx;
                        q.push(pii(nx, ny));
                    }
                }
            }
            idx++;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if(cnt[i][j] != cnt[nx][ny]) {
                        g[cnt[i][j]].insert(cnt[nx][ny]);
                        g[cnt[nx][ny]].insert(cnt[i][j]);
                    }
                }
            }
        }
    }
    vst[1] = 1;
    for(int i = 2; i < idx; i++) {
        if(!ans[i]) dfs(i, 0, 2);
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == '.') cout << '.';
            else if(ans[cnt[i][j]] > 1) cout << 'X';
            else cout << 'O';
        }
        cout << '\n';
    }
}