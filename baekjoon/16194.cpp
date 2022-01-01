#include <iostream>

using namespace std;

int dp[1001];

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> dp[i];
        for(int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
    }

    cout << dp[N];
}