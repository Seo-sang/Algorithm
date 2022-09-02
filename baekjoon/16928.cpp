#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 101;
const int INF = 1e9;
int N, M; 
int mover[MN];
int dp[MN];

void dfs(int now, int cnt) {
    for(int i = 1; i <= 6; i++) {
        int nxt = (mover[now + i] == 0 ? now + i : mover[now + i]);
        if(nxt > 100) continue;

        if(dp[nxt] > cnt + 1) {
            dp[nxt] = cnt + 1;
            dfs(nxt, cnt + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    fill(dp, dp + MN, INF);
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        mover[x] = y;
    }
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        mover[u] = v;
    }
    dp[1] = 0;
    dfs(1, 0);
    cout << dp[100];
}