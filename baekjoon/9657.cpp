#include <iostream>

using namespace std;

int dp[1001];

int main() {
    int N; cin >> N;
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    for(int i = 5; i <= N; i++) {
        int mnum = 1;
        mnum = min(mnum, dp[i - 1]);
        mnum = min(mnum, dp[i - 3]);
        mnum = min(mnum, dp[i - 4]);
        dp[i] = mnum == 0 ? 1 : 0;
    }
    if(dp[N]) cout << "SK";
    else cout << "CY";
}