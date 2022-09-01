#include <bits/stdc++.h>

using namespace std;
const int MN = 1e6 + 1;
const int INF = 1e9;
int dp[MN];
int F, S, G, U, D;

void dfs(int now, int cnt) {
    int nxt = now + U;
    if(nxt <= F && dp[nxt] > cnt + 1) {
        dp[nxt] = cnt + 1;
        dfs(nxt, cnt + 1);
    }
    nxt = now - D;
    if(nxt > 0 && dp[nxt] > cnt + 1) {
        dp[nxt] = cnt + 1;
        dfs(nxt, cnt + 1);
    }
}

int main() {
    cin >> F >> S >> G >> U >> D;
    fill(&dp[0], &dp[MN], INF);
    dp[S] = 0;
    dfs(S, 0);

    if(dp[G] == INF) cout << "use the stairs";
    else cout << dp[G];
}