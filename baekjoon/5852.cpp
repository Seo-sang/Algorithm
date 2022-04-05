#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 51;
const int INF = 1e9;
string board[MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int island[MN][MN];
int g[15][15];
int dist[MN][MN];
bool vst[MN][MN];
int dp[MN][1 << 15];
int R, C, N;

struct edge {
    int x, y, w;
    edge (int x, int y, int w) : x(x), y(y), w(w) {}
};

struct cmp {
    bool operator() (edge a, edge b) {
        return a.w < b.w;
    }
};

int TSP(int n, int bitmask) {
    int &ret = dp[n][bitmask];
    if(ret != -1) return ret;
    if(bitmask == (1 << N) - 1) {
        return 0;
    }

    ret = INF;
    for(int i = 0; i < N; i++) {
        if(g[n][i] == INF) continue;
        ret = min(ret, TSP(i, bitmask | (1 << i)) + g[n][i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++)
        cin >> board[i];
    
    //섬 그룹 나누기
    N = 0;
    memset(island, -1, sizeof(island));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] != 'X' || vst[i][j]) continue;
            vst[i][j] = true;
            island[i][j] = N;
            queue<P> q; q.push(make_pair(i, j));
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                        if(vst[nx][ny] || board[nx][ny] == '.' || board[nx][ny] == 'S') continue;
                        vst[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                        island[nx][ny] = N;
                    }
                }
            }
            N++;
        }
    }
    
    fill(&g[0][0], &g[14][15], INF);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] != 'X') continue;
            priority_queue<edge, vector<edge>, cmp> pq;
            fill(&dist[0][0], &dist[R - 1][C], INF);
            pq.push(edge(i, j, 0));
            dist[i][j] = 0;
            //같은 섬 추가하기
            while(!pq.empty()) {
                edge now = pq.top(); pq.pop();
                if(now.w > dist[now.x][now.y]) continue;
                for(int d = 0; d < 4; d++) {
                    int nx = now.x + dx[d];
                    int ny = now.y + dy[d];
                    if(nx >= 0 && nx < R && ny >= 0 && ny < C) {
                        if(board[nx][ny] == '.') continue;
                        int cost = (board[nx][ny] == 'S' ? now.w + 1 : now.w);
                        if(dist[nx][ny] > cost) {
                            dist[nx][ny] = cost;
                            if(board[nx][ny] == 'S')
                                pq.push(edge(nx, ny, cost));
                            else if(board[nx][ny] == 'X' && island[i][j] != island[nx][ny]) {
                                g[island[i][j]][island[nx][ny]] = min(g[island[i][j]][island[nx][ny]], cost);
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < N; i++) {
        memset(dp, -1, sizeof(dp));
        ans = min(ans, TSP(i, (1 << i)));
    }
    cout << ans;

}