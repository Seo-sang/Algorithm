#include <iostream>

using namespace std;

long long dp[82];

int main() {
    int N; cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= N + 1; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout << dp[N] * 2 + dp[N + 1] * 2;
}