#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 33334;
int N;
long long dp[MN];
int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    cin >> N;
    dp[1] = 0;
    dp[2] = 2;
    dp[3] = 6;
    dp[4] = 18;
    for (int i = 5; i <= N; i++) {
        dp[i] = (dp[i-1]*3)%1000000009;
    }
    cout << dp[N];
}