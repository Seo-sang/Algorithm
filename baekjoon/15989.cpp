#include <bits/stdc++.h>

using namespace std;

const int MN = 10001;
int dp[MN];

int main() {
    int T; cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 4; i < MN; i++) {
        dp[i] = dp[i-1] + dp[i-2] - 1;
    }

    while(T--) {
        int N; cin >> N;
        cout << dp[N] << '\n';
    }
}