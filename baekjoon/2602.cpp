#include <bits/stdc++.h>

using namespace std;

const int MN = 101;
int dp[MN][21][2];
string str, devil, angel;

int dfs(int n, int now, bool turn) {
    if(now == str.size()) return 1;
    if(n == devil.size()) return 0;
    int &ret = dp[n][now][turn];
    if(ret != -1) return ret;
    ret = 0;

    char c = str[now];
    if(turn) { //devil
        for(int i = n; i < devil.size(); i++) {
            if(c == devil[i]) ret += dfs(i + 1, now + 1, !turn);
        }
    }
    else { //angel
        for(int i = n; i < angel.size(); i++) {
            if(c == angel[i]) ret += dfs(i + 1, now + 1, !turn);
        }
    }

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> str >> devil >> angel;
    cout << dfs(0, 0, 0) + dfs(0, 0, 1);
}