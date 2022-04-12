#include <bits/stdc++.h>

using namespace std;
const int MN = 17;
const int INF = 1e9;
int N, P;
int g[MN][MN], dp[1 << 16];

int dfs(int bitmask, int cnt) {
    if(cnt >= P) return 0;
    int &ret = dp[bitmask];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < N; i++) {
        if(bitmask & (1 << i)) {
            for(int j = 0; j < N; j++) {
                if(bitmask & (1 << j)) continue;
                int nxtbit = bitmask | (1 << j);
                ret = min(ret, dfs(nxtbit, cnt + 1) + g[i][j]);
            }
        }
    }

    return ret;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> g[i][j];
    string onoff; cin >> onoff >> P;

    int bitmask = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
        if(onoff[i] == 'Y') {
            bitmask |= (1 << i);
            cnt++;
        }
    }
    memset(dp, -1, sizeof(dp));
    int rst = dfs(bitmask, cnt);
    if(rst == INF) cout << -1;
    else cout << rst;
}