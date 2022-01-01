#include <iostream>
#include <cstring>

using namespace std;

int dp[3][4000];

int main() {
    int N; cin >> N;
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    if(N == 0) {
        cout << 0;
        return 0;
    }
    int rest;
    for(int i = 2; i <= N; i++) {
        rest = 0;
        for(int j = 0; j < 4000; j++) {
            dp[i % 3][j] = rest + dp[(i-1) % 3][j] + dp[(i-2) % 3][j];
            if(dp[i%3][j] > 9) {
                dp[i%3][j] -= 10;
                rest = 1;
            }
            else rest = 0;
        }
    }
    int i;
    for(i = 3999; i >= 0; i--)
        if(dp[N%3][i]) break;
    for(; i >= 0; i--)
        cout << dp[N%3][i];
}