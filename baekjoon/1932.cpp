#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];

int max(int a, int  b, int c) {
    return max(a, max(b, c));
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + arr[i][j], dp[i-1][j] + arr[i][j]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans;
}