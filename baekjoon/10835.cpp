#include <iostream>
#include <cstring>

using namespace std;

const int MN = 2001;
pair<int,int> card[MN];
int dp[MN][MN];
int N;

int dfs(int A, int B) {
    if(A == N + 1 || B == N + 1) return 0;
    if(dp[A][B] != -1) return dp[A][B];
    int &ret = dp[A][B];

    ret = max(ret, dfs(A + 1, B));
    ret = max(ret, dfs(A + 1, B + 1));
    if(card[A].first > card[B].second) {
        ret = max(ret, dfs(A, B + 1) + card[B].second);
    }

    return ret;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> card[i].first;
    for(int i = 0; i < N; i++) cin >> card[i].second;
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0);
}