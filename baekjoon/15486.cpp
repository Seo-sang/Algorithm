#include <iostream>

using namespace std;

const int MN = 1500002;

int dp[MN];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int T, P; cin >> T >> P;
        int end = i + T - 1;
        dp[i] = max(dp[i], dp[i-1]);
        if(end > N) continue;
        dp[end+1] = max(dp[end+1], dp[i] + P);
        ans = max(ans, dp[end+1]);
    }
    cout << ans;
}