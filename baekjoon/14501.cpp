#include <iostream>
#include <cstring>

using namespace std;

const int MN = 16;

int T[MN];
int P[MN];
int dp[MN];

int main() {
    int N; cin >> N;
    int i;
    for(i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    dp[T[1]] = P[1];
    int ans = dp[T[1]];
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(i + T[i] - 1 > N) continue;
            dp[i + T[i] - 1] = max(dp[i + T[i] - 1], dp[j] + P[i]);
            ans = max(ans, dp[i + T[i] - 1]);
            cout << i + T[i] - 1 << ' ' << ans << endl;
        }
    }
    for(int i = 1; i <= N; i++)
        cout << dp[i] << ' ';
    cout << endl;
    cout << ans;
}
