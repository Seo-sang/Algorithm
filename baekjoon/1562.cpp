#include <iostream>

using namespace std;

const int mod = 1e9;
int dp[101][10][1 << 10];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i <= 9; i++)
        dp[1][i][1 << i] = 1;

    for(int i = 2; i <= N; i++) {
        for(int s = 1; s < (1 << 10); s++) {
            dp[i][0][s | (1 << 0)] += dp[i-1][1][s];
            dp[i][0][s | (1 << 0)] %= mod;
            for(int j = 1; j < 9; j++) {
                dp[i][j][s | (1 << j)] += dp[i-1][j-1][s];
                dp[i][j][s | (1 << j)] += dp[i-1][j+1][s];
                dp[i][j][s | (1 << j)] %= mod;
            }
            dp[i][9][s | (1 << 9)] += dp[i-1][8][s];
            dp[i][9][s | (1 << 9)] %= mod;
        }
    }
    int ans = 0;
    for(int i = 0; i < 10; i++) {
        ans += dp[N][i][(1 << 10) - 1];
        ans %= mod;
    }

    cout << ans;
}