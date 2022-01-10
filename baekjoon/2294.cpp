#include <iostream>

using namespace std;

const int MK = 10001;
const int INF = 1e9;

int dp[MK];

int main() {
    int N, K; cin >> N >> K;
    fill(&dp[0], &dp[K + 1], INF);
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        if(a > K) continue;
        dp[a] = 1;
        for(int j = a + 1; j <= K; j++) {
            dp[j] = min(dp[j], dp[j - a] + 1);
        }
    }
    if(dp[K] == INF)
        cout << -1;
    else
        cout << dp[K];
}