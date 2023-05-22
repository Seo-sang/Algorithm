#include <bits/stdc++.h>

using namespace std;

const int MN = 10001;
int dp[MN];

int main() {
    int N, T; cin >> N >> T;


    for(int i = 1; i <= N; i++) {
        int K, S; cin >> K >> S;
        for(int j = T; j >= 0; j--) {
            if(j >= K) 
                dp[j] = max(dp[j], dp[j - K] + S);
        }
    }

    cout << dp[T];
}