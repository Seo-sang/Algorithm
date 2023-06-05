#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
const int INF = 1e9;
vector<int> arr;
int dp[MN][MN][MN];

int dfs(int n, int o1, int o2, int cnt) {
    if(n == arr.size()) return cnt;
    int &ret = dp[n][min(o1, o2)][max(o1, o2)];
    if(ret <= cnt) return ret;
    int tmp1 = dfs(n + 1, o1, arr[n], cnt + abs(arr[n] - o2));
    int tmp2 = dfs(n + 1, o2, arr[n], cnt + abs(arr[n] - o1));
    ret = min(tmp1, tmp2);

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    fill(&dp[0][0][0], &dp[MN-1][MN-1][MN], INF);
    int N; cin >> N;
    int open1, open2; cin >> open1 >> open2;
    int M; cin >> M;

    while(M--) {
        int a; cin >> a;
        arr.push_back(a);
    }
    cout << dfs(0, open1, open2, 0);

}