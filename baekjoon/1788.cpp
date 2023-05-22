#include <bits/stdc++.h>

using namespace std;
const int MN = 2000001;
const int PIVOT = 1e6;
const int MOD = 1e9;
int dp[MN];

int main() {
    int N; cin >> N;
    dp[PIVOT] = 0;
    dp[PIVOT + 1] = 1;
    for(int i = 1000002; i < MN; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    for(int i = PIVOT; i >= 0; i--)
        dp[i] = (dp[i+2] - dp[i+1]) % MOD;
    
    if(dp[N + PIVOT] > 0) cout << 1;
    else if(dp[N + PIVOT] == 0) cout << 0;
    else cout << -1;
    cout << '\n';
    cout << abs(dp[N + PIVOT]);
}