#include <iostream>

using namespace std;

int dp[2][41];

int main() {
    int T; cin >> T;
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][1] = 1;
    for(int i = 2; i <= 40; i++) {
        dp[0][i] = dp[0][i-1] + dp[0][i-2];
        dp[1][i] = dp[1][i-1] + dp[1][i-2];
    }
    while(T--) {
        int N; cin >> N;
        cout << dp[0][N] <<' ' << dp[1][N] << '\n';
    }
}