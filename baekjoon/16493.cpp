#include <bits/stdc++.h>

using namespace std;
const int MN = 201;
int dp[MN];

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        for(int j = N; j >= 0; j--) {
            if(j >= a)
                dp[j] = max(dp[j], dp[j - a] + b);
        }
    }

    cout << dp[N];
}