#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

int dp[12];

int main() {
    int T; cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 11; i++) {
        dp[i] += dp[i-1];
        dp[i] += dp[i-2];
        dp[i] += dp[i-3];
    }

    while(T--) {
        int N; cin >> N;
        cout << dp[N] << '\n';
    }
}