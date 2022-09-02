#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 11;
const int INF = 1e9;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int N, M;
int board[MN][MN];
bool vst[MN][MN];
int p[7];

struct node {
    int x, y, d;
    node(int x, int y, int d) : x(x), y(y), d(d) {}
};

vector<node> g;

bool cmp(node a, node b) {
    return a.d < b.d;
}

void dfs(int x, int y, int d, int cnt, int start) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
        if(board[nx][ny] != 0) {
            if(board[nx][ny] != start && cnt + 1 > 1)
                g.push_back(node(start, board[nx][ny], cnt + 1));
        }
        else
            dfs(nx, ny, d, cnt + 1, start);
    }
}

int find(int n) {
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    int idx = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0 || vst[i][j]) continue;
            idx++;
            vst[i][j] = true;
            board[i][j] = idx;
            queue<P> q; q.push(make_pair(i, j));
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if(board[nx][ny] == 0 || vst[nx][ny]) continue;
                        vst[nx][ny] = true;
                        board[nx][ny] = idx;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }

    // cout << endl;
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    //경로 구하기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0) continue;
            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if(board[nx][ny] != 0) continue;
                    dfs(nx, ny, d, 0, board[i][j]);
                }
            }
        }
    }

    for(int i = 1; i < idx; i++)
        p[i] = i;

    sort(g.begin(), g.end(), cmp);
    int ans = 0, cnt = 1;
    for(node e : g) {
        //cout << e.x << ' ' << e.y << ' ' << e.d << endl;
        int p1 = find(e.x);
        int p2 = find(e.y);
        if(p1 == p2) continue;
        p[p1] = p2;
        ans += e.d;
    }
    int pp = find(1);
    for(int i = 2; i < idx; i++)
        if(p[i] == pp) cnt++;

    if(cnt == idx - 1) cout << ans;
    else cout << -1;
}