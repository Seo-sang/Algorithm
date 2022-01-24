#include <bits/stdc++.h>

using namespace std;
const int MN = 9;
const int MD = 100001;
const int MOD = 1e9 + 7;
int arr[MN][MN] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 0}
};

int dp[2][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int D; cin >> D;
    dp[1][2] = dp[1][3] = 1;
    for(int i = 2; i <= D; i++) {
        fill(&dp[i % 2][0], &dp[i %2][9], 0);
        for(int j = 1; j <= 8; j++) {
            for(int k = 1; k <= 8; k++) {
                if(arr[j][k]) {
                    dp[i%2][k] += dp[(i-1) % 2][j];
                    dp[i % 2][k] %= MOD;
                }
            }
        }
    }

    cout << dp[D % 2][1];
}