#include <iostream>

using namespace std;

const int MN = 1e5;
const int INF = 1e9;
int dp[MN];

int main() {
    int N; cin >> N;
    fill(dp, dp + N + 1, INF);
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    for(int i = 6; i <= N; i++)
        dp[i] = min(min(dp[i], dp[i-2] + 1), dp[i-5] + 1);
    
    if(dp[N] == INF) cout << -1;
    else cout << dp[N];
}