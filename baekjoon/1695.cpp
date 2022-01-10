#include <iostream>

using namespace std;

const int MN = 5001;

int s1[MN];
int s2[MN];
int dp[MN][MN];
int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> s1[i];
        s2[N - i + 1] = s1[i];
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << N - ans;
}