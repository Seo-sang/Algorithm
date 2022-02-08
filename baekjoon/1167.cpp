#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
vector<pair<int,int> > g[MN];
int h[MN];

void dfs(int n, int prev) {
    for(pair<int,int> e : g[n]) {
        if(e.first == prev) continue;
        h[e.first] = h[n] + e.second;
        dfs(e.first, n);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int V; cin >> V;
    for(int i = 0; i < V; i++) {
        int u; cin >> u;
        int v, d;
        while(true) {
            cin >> v;
            if(v == -1) break;
            cin >> d;
            g[u].push_back(make_pair(v, d));
        }
    }

    dfs(1, 0);
    int ans = 0;
    for(int i = 1; i <= V; i++) 
        if(h[ans] < h[i]) ans = i;

    memset(h, 0, sizeof(h));
    dfs(ans ,0);

    ans = 0;
    for(int i = 1; i <= V; i++)
        if(h[ans] < h[i]) ans = i;

    cout << h[ans];
}