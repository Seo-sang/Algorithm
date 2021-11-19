#include <iostream>

using namespace std;

int arr[10001];
int dp[10001];

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i], dp[i-1]);
    }

    cout << dp[N];
}