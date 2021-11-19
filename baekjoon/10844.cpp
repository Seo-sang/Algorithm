#include <iostream>

using namespace std;

long long dp[101][11];
const int MOD = 1e9;
int main() {
    int N; cin >> N;
    for(int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 0; i <= 9; i++) {
        ans += dp[N][i];
        ans %= MOD;
    }
    cout << ans;
}