#include <iostream>

using namespace std;

int V[51];
int dp[51][1001];

int main() {
    int N, S, M; cin >> N >> S >> M;
    for(int i = 1; i <= N; i++) {
        cin >> V[i];
    }
    dp[0][S] = 1;
    int ans = -1;
    for(int i = 1; i <= N; i++) {
        bool chk = false;
        ans = 0;
        for(int j = 0; j <= M; j++) {
            if(dp[i-1][j]) {
                if(j + V[i] >= 0 && j + V[i] <= M) {
                    dp[i][j + V[i]] = 1;
                    ans = max(ans, j + V[i]);
                    chk = true;
                }
                if(j - V[i] >= 0 && j - V[i] <= M) {
                    dp[i][j - V[i]] = 1;
                    ans = max(ans, j - V[i]);
                    chk = true;
                }
            }
        }
        if(!chk) {
            ans = -1;
            break;
        }
    }

    cout << ans;
}