#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
vector<int> g[MN];
int vst[MN];
int cnt = 2;

void dfs(int now) {
    for(int nxt : g[now]) {
        if(vst[nxt] > 0) continue;
        vst[nxt] = cnt++;
        dfs(nxt);
    }
}

int main() {
    int N, M, R; cin >> N >> M >> R;

    while(M--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) sort(g[i].begin(), g[i].end());
    vst[R] = 1;
    dfs(R);

    for(int i = 1; i <= N; i++) cout << vst[i] << '\n';
}