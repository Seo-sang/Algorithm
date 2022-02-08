#include <bits/stdc++.h>

using namespace std;

const int MN = 500001;
vector<int> g[MN];
int leaf;
void dfs(int n, int prev) {
    int cnt = 0;
    for(int e : g[n]) {
        if(e == prev) continue;
        cnt++;
        dfs(e, n);
    }
    if(cnt == 0) leaf++;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, W; cin >> N >> W;
    for(int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    double ans = (double) W / leaf;
    cout.precision(10);
    cout << fixed;
    cout << ans;
}