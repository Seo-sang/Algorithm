#include <iostream>

using namespace std;

long long dp[61][61];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    for(int i = 1; i <= 30; i++) dp[i][0] = 1;

    for(int i = 1; i <= 30; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            
    int N;
    while(true) {
        cin >> N;
            
        if(!N) break;
        long long ans = 0;

        for(int i = 1; i <= N; i++) {
            ans += dp[i][2 *N - i];
        }

        cout << ans << '\n';
    }
}