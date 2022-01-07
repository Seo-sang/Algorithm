#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1e9 + 3;
const int MN = 1001;

int dp[MN][MN]; //경우의 수 저장

int dfs(int N, int K) {
    if(K == 1 || K == 0) return dp[N][K] = N;
    if(N / 2 < K) return dp[N][K] = 0;
    if(dp[N][K] != -1) return dp[N][K];

    int &ret = dp[N][K] = 0;
    ret = dfs(N - 1, K) + dfs(N - 2, K - 1);
    ret %= mod;
    return ret;
}

int main() {
    int N, K; cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << dfs(N, K);
}