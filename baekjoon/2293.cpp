#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 101;
const int MK = 10001;

int coin[MN];
int dp[MK];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> coin[i];

    sort(coin, coin + N + 1);
    dp[0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = coin[i]; j <= K; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[K];
}