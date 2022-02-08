#include <bits/stdc++.h>

using namespace std;
const int MN = 10001;
vector<int> g[MN];
int dp[20][MN];
int h[MN];
bool root[MN];

void dfs(int n, int prev) {
    for(int e : g[n]) {
        if(e == prev) continue;
        h[e] = h[n] + 1;
        dp[0][e] = n;
        dfs(e, n);
    }
}

int LCA(int a, int b) {
    if(h[a] < h[b]) swap(a, b);
    int gap = h[a] - h[b];

    for(int i = 0; i < 20; i++)
        if(gap & (1 << i))
            a = dp[i][a];

    if(a == b) return a;

    for(int i = 19; i >= 0; i--)
        if(dp[i][a] != dp[i][b])
            a = dp[i][a], b = dp[i][b];

    return dp[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(h, 0, sizeof(h));
        memset(root, 0, sizeof(root));
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < MN; i++)
            g[i].clear();

        int N; cin >> N;
        for(int i = 0; i < N - 1; i++) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            root[b] = true;
        }
        int r;
        for(r = 1; r <= N; r++)
            if(root[r] == false) break;

        dfs(r, 0);

        for(int i = 1; i < 20; i++) {
            for(int j = 1; j <= N; j++) {
                dp[i][j] = dp[i-1][dp[i-1][j]];
            }
        }
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}