#include <bits/stdc++.h>

using namespace std;

int C, N; 
const int MN = 21;
const int INF = 1e9;
int cost[MN], consumer[MN];
int dp[1001][21];

int dfs(int c, int n) {
    if(c <= 0) return 0;
    if(dp[c][n] != -1) return dp[c][n];
    int &ret = dp[c][n];
    ret = INF;

    for(int i = 1; i <= N; i++) {
        ret = min(ret, dfs(c - consumer[i], n) + cost[i]);
    }

    return ret;
}

int main() {
    cin >> C >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= N; i++)
        cin >> cost[i] >> consumer[i];


    cout << dfs(C, N);
}