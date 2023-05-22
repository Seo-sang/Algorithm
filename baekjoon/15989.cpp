#include <bits/stdc++.h>

using namespace std;

const int MN = 10001;
int dp[MN][4];

int main() {
    int T; cin >> T;
    dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int i = 4; i < MN; i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    while(T--) {
        int N; cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
    }
}