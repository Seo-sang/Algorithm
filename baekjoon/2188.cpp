#include <bits/stdc++.h>

using namespace std;
const int MN = 402;
const int INF = 1e9;
vector<int> g[MN];
int c[MN][MN];
int f[MN][MN];
int d[MN];

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
    int N, M; cin >> N >> M;
    M += 200;
    for(int i = 201; i <= M; i++) {
        g[i].push_back(M + 1);
        g[M+1].push_back(i);
        c[i][M + 1]++;
    }
    //소는 1부터 축는 201부터
    for(int i = 1; i <= N; i++) {
        g[i].push_back(0);
        g[0].push_back(i);
        c[0][i]++;
        int S; cin >> S;
        while(S--) {
            int n; cin >> n;
            n += 200;
            g[i].push_back(n);
            g[n].push_back(i);
            c[i][n] += 1;
        }
    }
    cout << maxflow(0, M + 1);
}