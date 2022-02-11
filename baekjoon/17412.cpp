#include <bits/stdc++.h>

using namespace std;
const int MN = 401;
const int INF = 1e9;

int c[MN][MN];
int f[MN][MN];
vector<int> g[MN];
int d[MN];

int maxflow(int src, int snk) {
    int ret = 0;
    while(1) {
        queue<int> q; q.push(src);
        memset(d, -1, sizeof(d)); d[src] = src;
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int nxt : g[now]) {
                if(c[now][nxt] - f[now][nxt] > 0 && d[nxt] == -1) {
                    q.push(nxt);
                    d[nxt] = now;
                }
            }
        }
        if(d[snk] == -1) break;
        int flow = INF;
        for(int i = snk; i != src; i = d[i])
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);

        for(int i = snk; i != src; i = d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }

        ret += flow;
    }

    return ret;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, P; cin >> N >> P;
    while(P--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        c[u][v]++;
    }

    cout << maxflow(1, 2);
}