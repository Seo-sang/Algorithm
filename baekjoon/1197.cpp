#include <bits/stdc++.h>

using namespace std;

struct edge {
    int w, u, v;
};
const int MN = 10001;
int p[MN];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find(int n) {
    if(n == p[n]) return n;
    else return p[n] = find(p[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int V, E; cin >> V >> E;
    vector<edge> arr;
    while(E--) {
        int u, v, w; cin >> u >> v >> w;
        arr.push_back({w, u, v});
    }
    sort(arr.begin(), arr.end(), cmp);

    for(int i = 1; i <= V; i++)
        p[i] = i;

    int ans = 0;
    for(edge e : arr) {
        if(find(e.u) == find(e.v)) continue;
        ans += e.w;
        p[find(e.u)] = e.v;
    }

    cout << ans;
}