#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
vector<int> g[MN];
bool vst[MN];

void dfs(int n) {
    for(int nxt : g[n]) {
        if(vst[nxt]) continue;
        vst[nxt] = true;
        dfs(nxt);
    }
}

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(vst[i]) continue;
        vst[i] = true;
        ans++;
        dfs(i);
    }

    cout << ans;
}