#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
vector<int> g[MN];
int ans[MN];

void dfs(int n, int w) {
    ans[n] += w;
    for(int nxt : g[n]) 
        dfs(nxt, ans[n]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 1 ; i <= N; i++) {
        int a; cin >> a;
        if(i == 1) continue;
        g[a].push_back(i);
    }
    while(M--) {
        int i, w; cin >> i >> w;
        ans[i] += w;
    }
    dfs(1, 0);

    for(int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
}