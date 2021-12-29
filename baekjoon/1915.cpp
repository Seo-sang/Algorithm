#include <iostream>

using namespace std;

string board[1001];

int dp[1001][1001];

int main() {
    int N, M; cin >> N >> M;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        cin >> board[i];
        board[i] = ' ' + board[i];
    }

    for(int i = 1 ;i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(board[i][j] == '1') {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans * ans;
}