#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 10001;
vector<P> arr;
int dp[101][MN];
int T, K;

int dfs(int turn, int money) {

    if(turn == K) {
        if(money == 0) return 1;
        else return 0;
    }

    int &ret = dp[turn][money];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i <= arr[turn].second; i++) {
        if(money >= arr[turn].first * i)
            ret += dfs(turn + 1, money - arr[turn].first * i);
    }

    return ret;
}

int main() {
    cin >> T >> K;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < K; i++) {
        int p, n; cin >> p >> n;
        arr.push_back(make_pair(p, n));
    }

    cout << dfs(0, T);
}