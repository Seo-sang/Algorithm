#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
vector<int> g[MN];
bool vst[MN];
int ans = 0;

void dfs(int n) {
    for(int nxt : g[n]) {
        if(vst[nxt]) continue;
        vst[nxt] = true;
        ans++;
        dfs(nxt);
    }
}

int main() {
    int N, M; cin >> N >> M;
    while(M--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vst[1] = true;
    dfs(1);
    cout << ans;
}