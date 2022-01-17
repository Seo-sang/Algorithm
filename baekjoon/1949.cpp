#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MN = 10001;

int people[MN];
vector<int> g[MN];

//0은 안포함, 1은 포함
int dp[MN][2];
bool visit[MN];

int dfs(int n, int in, int prev) {
    if(dp[n][in] != -1) return dp[n][in];
    int &ret = dp[n][in];
    ret = 0;
    if(in == 0) {
        for(int e : g[n]) {
            if(e == prev) continue;
            ret += max(dfs(e, 0, n), dfs(e, 1, n));
        }
    }
    else {
        for(int e : g[n]) {
            if(e == prev) continue;
            ret += dfs(e, 0, n);
        }
        ret += people[n];
    }
    return ret;
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) 
        cin >> people[i];

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << max(dfs(1,0, 0), dfs(1, 1, 0));
}