#include <bits/stdc++.h>

using namespace std;

const int MN = 15;
int dp[MN][MN];

int main() {
    int T; cin >> T;

    for(int i = 1; i < MN; i++)
        dp[0][i] = i;

    for(int i = 1; i < MN; i++)
        for(int j = 1; j < MN; j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][j];

    while(T--) {
        int K, N; cin >> K >> N;
        cout << dp[K][N] << '\n';
    }
}