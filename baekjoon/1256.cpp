#include <iostream>
#include <vector>
using namespace std;

const int MN = 10001;

long long dp[101][101];
int INF = 1e9;

int main() {
    int N, M, K; cin >> N >> M >> K;
    for(int i = 1; i <= max(N, M); i++)
        dp[i][0] = 1, dp[0][i] = 1;
    
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(dp[i][j] > INF) dp[i][j] = INF;
        }
    }

    if(dp[N][M] < K) {
        cout << -1;
        return 0;
    }

    string ans = "";
    int a = N, z = M;
    for(int i = 0; i < N + M; i++) {
        if(a == 0) {
            ans += 'z';
            z--;
        }
        else if(z == 0) {
            ans += 'a';
            a--;
        }
        else if(dp[a-1][z] >= K) {
            ans += 'a';
            a--;
        }
        else {
            K -= dp[a-1][z];
            ans += 'z';
            z--;
        }
    }
    cout << ans;
}