#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int arr[1001];
int dp[1001];

int N;
void dfs(int n) {
    for(int i = 1; i <= arr[n]; i++) {
        if(n + i > N) break;
        if(dp[n + i] > dp[n] + 1) {
            dp[n + i] = dp[n] + 1;
            dfs(n + i);
        }
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    fill(dp, dp + N + 1, INF);
    dp[1] = 0;
    dfs(1);

    if(dp[N] == INF) cout << -1;
    else cout << dp[N];
}