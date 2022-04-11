#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 117;
ll dp[MN];

int main() {
    dp[1] = dp[2] = dp[3] = 1;
    int N; cin >> N;
    for(int i = 4; i <= N; i++)
        dp[i] = dp[i-1] + dp[i-3];
    cout << dp[N];
}