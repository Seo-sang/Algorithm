#include <bits/stdc++.h>

using namespace std;
const int MN = 802;
const int INF = 1e9;
vector<int> g[MN];
int c[MN][MN];
int f[MN][MN];
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
            f[p[i]][i] += flow;
            f[i][p[i]] -= flow;
        }
        ret += flow;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, P; cin >> N >> P;
    for(int i = 1; i <= N; i++) {
        g[i].push_back(i + 400);
        g[i + 400].push_back(i);
        c[i][i + 400]++;
    }
    for(int i = 0; i < P; i++) {
        int a, b; cin >> a >> b;
        g[a + 400].push_back(b);
        g[b].push_back(a + 400);
        g[b + 400].push_back(a);
        g[a].push_back(b + 400);
        c[a + 400][b] += 1;
        c[b + 400][a] += 1;
    }

    cout << maxflow(401, 2);
}