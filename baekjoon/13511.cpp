#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;

const int MN = 100001;
vector<P> g[MN];
int h[MN], dp[20][MN];
ll cost[20][MN];

void dfs(int n, int prev) {
    for(P nxt : g[n]) {
        if(nxt.first == prev) continue;
        h[nxt.first] = h[n] + 1;
        dp[0][nxt.first] = n;
        cost[0][nxt.first] = nxt.second;
        dfs(nxt.first, n);
    }
}

int LCA(int a, int b) {
    if(h[a] < h[b]) swap(a, b);

    int gap = h[a] - h[b];

    for(int i = 0; i < 20; i++) {
        if(gap & (1 << i))
            a = dp[i][a];
    }

    if(a == b) return a;

    for(int i = 19; i >= 0; i--) {
        if(dp[i][a] != dp[i][b]) {
            a = dp[i][a];
            b = dp[i][b];
        }
    }

    return dp[0][a];
}

ll get_cost(int a, int b) {
    if(a == b) return 0;
    ll ret = 0;
    int i;
    int gap = h[b] - h[a];
    for(i = 0; i < 20; i++) {
        if(gap & (1 << i)) {
            ret += cost[i][b];
            b = dp[i][b];
        }
    }

    return ret;
}

int get_dist(int p, int a, int b, int k) {
    if(k <= h[a] - h[p]) {
        for(int i = 0; i < 20; i++) {
            if(k & (1 << i)) {
                a = dp[i][a];
            }
        }

        return a;
    }
    else {
        k = h[b] - h[p] - (k - (h[a] - h[p]));
        for(int i = 0; i < 20; i++) {
            if(k & (1 << i))
                b = dp[i][b];
        }

        return b;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    dfs(1, 0);

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= N; j++) {
            int k = dp[i-1][j];
            dp[i][j] = dp[i-1][k];
            cost[i][j] = cost[i-1][k] + cost[i-1][j];
        }
    }

    int M; cin >> M;
    while(M--) {
        int a, u, v, k; cin >> a >> u >> v;
        int p = LCA(u, v);
        if(a == 1) {
            cout << get_cost(p, u) + get_cost(p, v) << '\n';
        }
        else {
            cin >> k;
            cout << get_dist(p, u, v, k - 1) << '\n';
        }
    }
}