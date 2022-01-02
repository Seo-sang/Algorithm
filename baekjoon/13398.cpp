#include <iostream>

using namespace std;

const int MN = 100001;
const int INF = 1e9;
int dp[MN];
int dp2[MN];
int arr[MN];
int main() {
    int N; cin >> N;
    int ans = -INF;
    fill(dp, dp + N + 1, -INF);
    fill(dp2, dp2 + N + 1, -INF);
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        ans = max(ans, dp[i]);
        dp2[i] = max(dp[i-1], dp2[i-1] + arr[i]);
        ans = max(ans, dp2[i]);
    }
    cout << ans;
}