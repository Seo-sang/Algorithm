#include <iostream>
#include <cstring>

using namespace std;

const int MN = 1e6;
long long dp[MN + 1];

int main() {
    int T; cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= MN; i++) {
        for(int j = 1; j <= 3; j++) {
            dp[i] += dp[i-j];
            dp[i] %= 1000000009;
        }
    }

    while(T--) {
        int N; cin >> N;
        cout << dp[N] << '\n';
    }
}