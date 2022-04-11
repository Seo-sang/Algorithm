#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 1001;
const int INF = 1e9;
vector<P> g[MN];

int dfs(int n, int prev) {
    int ret = 0;
    for(P nxt : g[n]) {
        if(nxt.second == prev) continue;
        int d = dfs(nxt.second, n);
        ret += (d == 0 ? nxt.first : min(d, nxt.first));
    }

    return ret;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        for(int i = 0; i <= N; i++)
            g[i].clear();
        while(M--) {
            int u, v, w; cin >> u >> v >> w;
            g[u].push_back(make_pair(w, v));
            g[v].push_back(make_pair(w, u));
        }
        cout << dfs(1, 0) << '\n';
    }
}