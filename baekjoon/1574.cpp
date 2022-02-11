#include <bits/stdc++.h>

using namespace std;
const int MN = 602;
const int INF = 1e9;
vector<int> g[MN];
int c[MN][MN];
int f[MN][MN];
int RC[301][301];
int p[MN];

int maxflow(int src, int snk) {
    int ret = 0;
    while(1) {
        queue<int> q; q.push(src);
        memset(p, -1, sizeof(p));
        p[src] = src;
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int nxt : g[now]) {
                if(c[now][nxt] - f[now][nxt] > 0 && p[nxt] == -1) {
                    q.push(nxt);
                    p[nxt] = now;
                }
            }
        }
        if(p[snk] == -1) break;
        int flow = INF;
        for(int i = snk; i != src; i = p[i])
            flow = min(flow, c[p[i]][i] - f[p[i]][i]);

        for(int i = snk; i != src; i = p[i]) {
            f[p[i]][i]+=flow;
            f[i][p[i]]-=flow;
        }

        ret += flow;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int R, C, N; cin >> R >> C >> N;
    C += 300;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        RC[a][b] = 1;
    }

    for(int i = 301; i <= C; i++) {
        g[i].push_back(C + 1);
        g[C + 1].push_back(i);
        c[i][C + 1]++;
    }

    for(int i = 1; i <= R; i++) {
        g[0].push_back(i);
        g[i].push_back(0);
        c[0][i]++;
        for(int j = 301; j <= C; j++) {
            if(!RC[i][j - 300]) {
                g[i].push_back(j);
                g[j].push_back(i);
                c[i][j]++;
            }
        }
    }

    cout << maxflow(0, C + 1);
}