#include <iostream>

using namespace std;

pair<int,int> dp[46];

int main() {
    int K; cin >> K;
    dp[0] = {1, 0};
    for(int i = 1; i <= K; i++) {
        int a = dp[i-1].second;
        int b = dp[i-1].first + dp[i-1].second;
        dp[i].first = a;
        dp[i].second = b;
    }

    cout << dp[K].first << ' ' << dp[K].second;
}