#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 1e6;
int dp[MN + 1];

int main() {
    int N; cin >> N;
    fill(dp, dp + N + 1, MN);
    dp[N] = 0;
    for(int i = N; i > 1; i--) {
        dp[i-1] = min(dp[i-1], dp[i] + 1);
        if(i % 3 == 0)
            dp[i / 3] = min(dp[i/3], dp[i] + 1);
        if(i % 2 == 0)
            dp[i / 2] = min(dp[i/2], dp[i] + 1);
    }
    cout << dp[1];
}