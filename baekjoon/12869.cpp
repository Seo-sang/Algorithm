#include <bits/stdc++.h>

using namespace std;

const int MN = 61;
int dp[MN][MN][MN];
int arr[3];

int dfs(int a, int b, int c) {
    if(a + b + c == 0) return 0;
    if(dp[a][b][c] != -1) return dp[a][b][c];

    int &ret = dp[a][b][c];
    ret = 0;

    //123
    ret = 1 + dfs(max(0, a - 9), max(0, b - 3), max(0, c - 1));
    //132
    ret = min(ret, 1 + dfs(max(0, a - 9), max(0, b - 1), max(0, c - 3)));
    //213
    ret = min(ret, 1 + dfs(max(0, a - 3), max(0, b - 9), max(0, c - 1)));
    //231
    ret = min(ret, 1 + dfs(max(0, a - 3), max(0, b - 1), max(0, c - 9)));
    //312
    ret = min(ret, 1 + dfs(max(0, a - 1), max(0, b - 9), max(0, c - 3)));
    //321
    ret = min(ret, 1 + dfs(max(0, a - 1), max(0, b - 3), max(0, c - 9)));

    return ret;
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
        
    memset(dp, -1, sizeof(dp));

    cout << dfs(arr[0], arr[1], arr[2]);
}