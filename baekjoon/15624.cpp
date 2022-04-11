#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
int dp[2];
int main() {
    int N; cin >> N;
    dp[1] = 1;
    for(int i = 2; i <= N; i++)
        dp[i % 2] = (dp[(i-1) % 2] + dp[(i-2) % 2]) % MOD;
    cout << dp[N % 2];
}