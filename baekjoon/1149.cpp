#include <iostream>

using namespace std;

const int MN = 1001;

int arr[MN][MN];

int dp[MN][4];

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];
    dp[1][2] = arr[1][2];
    dp[1][3] = arr[1][3];

    for(int i = 2; i <= N; i++) {
        dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + arr[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + arr[i][2];
        dp[i][3] = min(dp[i-1][2], dp[i-1][1]) + arr[i][3];
    }

    cout << min(dp[N][1], dp[N][2], dp[N][3]);
}