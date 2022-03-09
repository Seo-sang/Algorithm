#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
const int INF = 1e9;
vector<int> g[MN];
int dp[19][MN];

int dfs(int n, int prev, int color) {
    if(dp[color][n] != -1)
        return dp[color][n];

    int &ret = dp[color][n];
    ret = color;
    for(int nxt : g[n]) {
        if(nxt == prev) continue;
        int tmp = INF;
        for(int i = 1; i <= 18; i++) {
            if(i == color ) continue;
            tmp = min(tmp, dfs(nxt, n, i));
        }
        ret += tmp;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0;  i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    int ans = INF;
    for(int i = 1; i <= 18; i++)
        ans = min(ans, dfs(1, 0, i));
    cout << ans;
}