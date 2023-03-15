#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
vector<int> g[MN];
int dp[MN][4];
int painted[MN];

int dfs(int now, int color, int prev) {
    if(dp[now][color] != -1) return dp[now][color];
    int &ret = dp[now][color];
    ret = 0;
    bool chk = false;
    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        chk = true;
        if(painted[nxt] != 0) {
            if(color == painted[nxt]) {
                return 0;
            }
            else {
                return ret = dfs(nxt, painted[nxt], now);
            }
        }
        for(int c = 1; c <= 3; c++) {
            if(color == c) continue;
            ret += dfs(nxt, c, now);
        }
    }
    if(!chk) ret = 1;
    
    cout << now << ' ' << ret << endl;
    return ret;
}

int main() {
    int N, K; cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    while(K--) {
        int b, c; cin >> b >> c;
        painted[b] = c;
    }

    g[0].push_back(1);

    cout << dfs(0, 0, -1);
}