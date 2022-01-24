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

int dp[MD][MN];

int main() {
    int D; cin >> D;
    for(int i = 1; i <= D; i++) {
        for(int j = 1; j <= 8; j++) {
            for(int k = 1; k <= 8; k++) {
                if(arr[j][k]) {
                    dp[i][k] += dp[i-1][j] + 1;
                    dp[i][k] %= MOD;
                    cout << i << ' ' << j << ' ' <<k << ' ' << dp[i][k] << endl;
                }
            }
        }
    }

    cout << dp[D][1];
}