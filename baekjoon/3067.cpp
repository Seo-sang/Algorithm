#include <bits/stdc++.h>

using namespace std;

const int MN = 21;
const int MM = 10001;
int arr[MN];
int dp[MM][MN];

int main() {
    int T; cin >> T;
    while(T--) {
        memset(dp, 0, sizeof(dp));
        int N, M; cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
            dp[arr[i]][i] = 1;
        }
        cin >> M;
        for(int i = 0; i <= M; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[j] > i) continue;
                for(int k = 0; k <= j; k++)
                    dp[i][j] += dp[i - arr[j]][k];
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++) ans += dp[M][i];
        cout << ans << '\n';
    }

}