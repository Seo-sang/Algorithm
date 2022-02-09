#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 40001;
vector<P> g[MN];
int h[MN];
int score[MN];
int dp[20][MN];

void dfs(int n, int prev) {
    for(P nxt : g[n]) {
        if(nxt.first == prev) continue;
        h[nxt.first] = h[n] + 1;
        score[nxt.first] = score[n] + nxt.second;
        dp[0][nxt.first] = n;
        dfs(nxt.first, n);
    }
}

int LCA(int a, int b) {
    if(h[a] < h[b]) swap(a, b);

    int gap = h[a] - h[b];

    for(int i = 0; i < 20; i++)
        if(gap & (1 << i))
            a = dp[i][a];

    if(a == b) return a;

    for(int i = 19; i >= 0; i--)
        if(dp[i][a] != dp[i][b])
            a = dp[i][a], b = dp[i][b];

    return dp[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N -1; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(1, 0);

    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= N; j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];

    int M; cin >> M;
    while(M--) {
        int u, v; cin >> u >> v;
        int p = LCA(u, v);
        cout << score[u] + score[v] - (score[p] * 2) << '\n';
    }
}