#include <bits/stdc++.h>

using namespace std;
int N, M, R;
const int MN = 100001;
vector<int> g[MN];
int vst[MN];
int cnt = 1;

void dfs(int now) {
    vst[now] = cnt++;
    for(int nxt : g[now]) {
        if(vst[nxt] > 0) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> R;

    while(M--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) sort(g[i].begin(), g[i].end(), greater<int>());

    dfs(R);

    for(int i = 1; i <= N; i++) cout << vst[i] << '\n';
}