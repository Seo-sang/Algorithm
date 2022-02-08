#include <bits/stdc++.h>

using namespace std;
const int MN = 10001;
struct edge {
    int w, v;
};
vector<edge> g[MN];
int h[MN];

void dfs(int n, int prev) {
    for(edge nxt : g[n]) {
        if(nxt.v == prev) continue;
        h[nxt.v] = h[n] + nxt.w;
        dfs(nxt.v, n);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge input = {w, v};
        g[u].push_back(input);
        edge input2 = {w, u};
        g[v].push_back(input2);
    }

    dfs(1, 0);
    int start = 0;
    for(int i = 1; i <= N; i++)
        if(h[i] > h[start]) start = i;

    memset(h, 0, sizeof(h));

    dfs(start, 0);

    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(h[i] > h[ans]) ans = i;

    cout << h[ans];
}