#include <iostream>

using namespace std;

int arr[16][16];
int dp[16][16];
int main() {
    int N, M, K; cin >> N >> M >> K;
    int n = 1;
    pair<int,int> pos;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j<= M; j++) {
            if(K == n) {
                pos.first = i;
                pos.second = j;
            }
            arr[i][j] = n++;
        }
    }
    dp[0][1] = 1;
    for(int i = 1; i <= N ; i++)
        for(int j = 1; j <= M; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];


    int ans;
    if(K) {
        ans = dp[pos.first][pos.second];
        ans *= dp[N - pos.first + 1][M - pos.second + 1];
    }
    else {
        ans = dp[N][M];
    }
    

    cout << ans;
}