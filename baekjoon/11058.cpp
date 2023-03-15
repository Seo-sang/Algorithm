#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 101;

ll dp[MN];

int main() {
    int N; cin >> N;

    for(int i = 1; i <= 3; i++)
        dp[i] = i;
    for(int i = 4; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 3; i - j > 0; j++)
            dp[i] = max(dp[i], dp[i-j] * (j - 1));
    }

    cout << dp[N];
}