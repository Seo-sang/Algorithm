#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
vector<int> g[MN];
int h[MN], dp[20][MN];

void dfs(int n, int prev) {
    for(int nxt : g[n]) {
        if(nxt == prev) continue;
        dp[0][nxt] = n;
        h[nxt] = h[n] + 1;
        dfs(nxt, n);
    }
}

int LCA(int a, int b) {
    if(h[a] < h[b]) swap(a, b);

    int gap = h[a] - h[b];
    //cout << h[a] << ' ' << h[b] << endl;
    for(int i = 0; i < 20; i++)
        if(gap & (1 << i))
            a = dp[i][a];

    if(a == b) return a;

    for(int i = 19; i >= 0; i--) {
        if(dp[i][a] != dp[i][b])
            a = dp[i][a], b = dp[i][b];
    }

    return dp[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    int M; cin >> M;
    while(M--) {
        int r, u, v; cin >> r >> u >> v;
        int cen = LCA(u, v);
        int left = LCA(r, u);
        int right = LCA(r, v);
        
        if(left == cen) 
            cout << right << '\n';
        else if(right == cen)
            cout << left << '\n';
        else
            cout << cen << '\n';
        
    }

}