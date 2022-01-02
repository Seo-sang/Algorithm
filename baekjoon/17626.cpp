#include <iostream>
#include <cmath>
using namespace std;

const int MN = 50001;
int dp[MN];

int main() {
    int N; cin >> N;
    fill(dp, dp + N + 1, MN);
    for(int i = 1; pow(i, 2) <= N; i++)
        dp[(int)pow(i, 2)] = 1;

    for(int i = 2; i <= N; i++) {
        if(dp[i] == 1) continue;
        for(int j = 1; j <= (i - pow(j, 2)); j++) {
            dp[i] = min(dp[i], dp[(int)pow(j, 2)] + dp[i - (int)pow(j, 2)]);
        }
    }
    

    cout << dp[N];
}