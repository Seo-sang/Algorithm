#include <bits/stdc++.h>

using namespace std;

const int MN = 50001;
int arr[MN], sum[MN];
int dp[3][MN];
int N, M; 

int dfs(int order, int n) {
    if(n >= N) return 0;
    if(order == 3) return 0;
    if(dp[order][n] != -1) return dp[order][n];

    int &ret = dp[order][n];
    ret = 0;
    ret = max(dfs(order, n + 1), dfs(order + 1, n + M) + sum[n]);

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cin >> M;

    int tmp = 0;
    for(int i = 0; i < M; i++) tmp += arr[i];
    sum[0] = tmp;
    for(int i = M; i < N; i++) {
        tmp = tmp + arr[i] - arr[i - M];
        sum[i - M + 1] = tmp;
    }

    cout << dfs(0, 0);

}