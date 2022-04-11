#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
int L[MN];
int J[MN];
int dp[MN][101];

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> L[i];
    for(int i = 1; i <= N; i++)
        cin >> J[i];
        
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 101; j++) {
            if(j <= L[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - L[i]] + J[i]);
        }
    }
    int ans = 0;
    for(int i = 0; i < 101; i++)
        ans = max(ans, dp[N][i]);
    cout << ans;
}