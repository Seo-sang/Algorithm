#include <iostream>

using namespace std;

int dp[1001][31][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, W; cin >> T >> W;
    int ans = 0;
    int a; cin >> a;

    if(a == 1) {
        dp[1][0][0] = 1;
        ans = 1;
    }
    else {
        dp[1][1][1] = 1;
        ans = 1;
    }

    for(int i = 2; i <= T; i++) {
        cin >> a;
        a--;
        for(int j = 0; j <= W; j++) {
            //안움직이고 먹기
            dp[i][j][a] = max(dp[i][j][a], dp[i-1][j][a] + 1);
            ans = max(ans, dp[i][j][a]);

            //움직이고 먹기
            if(j < W) {
                dp[i][j+1][a] = max(dp[i][j+1][a], dp[i-1][j][(a+1) % 2] + 1);
                ans = max(ans, dp[i][j+1][a]);
            }
            //안움직이고 안먹기
            dp[i][j][(a+1) % 2] = max(dp[i][j][(a+1) % 2], dp[i-1][j][(a+1) % 2]);
            ans = max(ans, dp[i][j][(a+1) % 2]);
        }
    }
    cout << ans;
}