#include <iostream>

using namespace std;

const int MN = 65;
long long dp[65][10];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for(int i = 0; i < 10; i++) dp[1][i] = 1;
    for(int i = 2; i < 65; i++)
        for(int j = 0; j < 10; j++) 
            for(int k = 0; k <= j; k++) 
                dp[i][j] += dp[i-1][k];

    while(T--) {
        int N; cin >> N;
        long long ans = 0;
        for(int i = 0; i < 10; i++)
            ans += dp[N][i];
        cout << ans << '\n';
    }
}