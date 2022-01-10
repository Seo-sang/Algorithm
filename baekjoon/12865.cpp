#include <iostream>

using namespace std;

int MN = 100001;
int dp[MN];

int main() {
    int N, K; cin >> N >> K;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int W, V; cin >> W >> V;
        for(int j = K; j >= 0; j--) {
            if(j >= W)
                dp[j] = max(dp[j], dp[j - W] + V);
        }
    }
    cout << dp[K];
}