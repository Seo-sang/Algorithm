#include <bits/stdc++.h>

using namespace std;
const int MN = 701;
const int INF = 1e9;
int c[MN][MN];
int f[MN][MN];
int d[MN];
vector<int> g[MN];

int maxflow(int src, int snk) {
    int ret = 0;

    while(1) {
        queue<int> q; q.push(src);
        memset(d, -1, sizeof(d));
        d[src] = src;
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
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        char a, b; int w; cin >> a >> b >> w;
        g[a].push_back(b);
        g[b].push_back(a);

        c[a][b] += w;
        c[b][a] += w;
    }

    cout << maxflow('A', 'Z');
}