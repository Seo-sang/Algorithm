#include <bits/stdc++.h>

using namespace std;
const int MN = 1024;
int h[MN];
int dp[11][MN];

void dfs(int n) {
    if(n * 2 < MN) {
        h[n * 2] = h[n] + 1;
        dp[0][n * 2] = n;
        dfs(n * 2);
    }
    if(n * 2 + 1 < MN) {
        h[n * 2 + 1] = h[n] + 1;
        dp[0][n * 2 + 1] = n;
        dfs(n * 2 + 1);
    }
}

int LCA(int a, int b) {
    if(h[a] < h[b]) swap(a, b);
    int gap = h[a] - h[b];

    for(int i = 0; i < 11; i++)
        if(gap & (1 << i))
            a = dp[i][a];
    if(a == b) return a;
    for(int i = 10; i >= 0; i--)
        if(dp[i][a] != dp[i][b])
            a = dp[i][a], b = dp[i][b];
    
    return dp[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    dfs(1);
    for(int i = 1; i < 11; i++)
        for(int j = 1; j < MN; j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];

    while(T--) {
        int A, B; cin >> A >> B;
        cout << LCA(A, B) * 10 << '\n';
    }
}