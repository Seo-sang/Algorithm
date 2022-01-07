#include <iostream>
#include <cstring>

using namespace std;

const int MN = 1001;
int arr[MN];
int dp[MN][MN][2];
int ans;

int dfs(int begin, int end, int turn) {
    if(begin > end) return 0;
    int &ret = dp[begin][end][turn];

    if(ret != -1) 
        return ret;

    int next = turn ? 0 : 1;
    int d1 = dfs(begin + 1, end, next);
    int d2 = dfs(begin, end - 1, next);
    if(turn == 0) ret = max(d1 + arr[begin], d2 + arr[end]);
    else ret = min(d1, d2);

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        cout << dfs(0, N-1, 0) << '\n';
    }
}