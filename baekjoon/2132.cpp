#include <bits/stdc++.h>

using namespace std;
const int MN = 10001;
vector<int> g[MN];
int grape[MN];
int h[MN];

void dfs(int n, int prev) {
    for(int e : g[n]) {
        if(e == prev) continue;
        h[e] = h[n] + grape[e];
        dfs(e, n);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> grape[i];

    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    h[1] = grape[1];
    dfs(1, 0);

    int start = 1;
    for(int i = 1; i <= N; i++)
        if(h[start] < h[i]) start = i;
    
    memset(h, 0, sizeof(h));
    h[start] = grape[start];
    dfs(start, 0);
    int ans = 1;
    for(int i = 1; i <= N; i++)
        if(h[ans] < h[i]) ans = i;
    
    start = min(start, ans);
    cout << h[ans] << ' ' << start;
}