#include <bits/stdc++.h>

using namespace std;
const int MN = 301;
int profit[MN][21], dp[MN][21], route[MN][21];
int N, M;

int ans = 0;

int dfs(int seed, int turn) {
    if(seed == N || turn == M + 1) return 0;
    
    int &ret = dp[seed][turn];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i <= N; i++) {
        if(seed + i > N) continue;
        int tmp = dfs(seed + i, turn + 1);
        if(ret <  tmp + profit[i][turn]) {
            ret = tmp + profit[i][turn];
            route[seed][turn] = i;
        }
    }

    return ret;
}

void back_track(int seed, int turn) {
    cout << route[seed][turn] << ' ';
    if(turn == M) return;
    back_track(seed + route[seed][turn], turn + 1);
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int seed; cin >> seed;
        for(int j = 1; j <= M; j++)
            cin >> profit[i][j];
    }
    memset(dp, -1, sizeof(dp));

    int ans = dfs(0, 1);

    cout << ans << '\n';
    for(int i = 0; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(dp[i][j] == ans) {
                back_track(i, j);
                return 0;
            }
        }
    }
}