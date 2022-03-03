#include <bits/stdc++.h>
using namespace std;
const int MN = 201;
const int INF = 1e9;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> g[MN];
int dp[101][MN];
vector<int> dest;

int dfs(int cnt, int now) {
    if(cnt == dest.size() - 1) {
        if(now == dest.back())
            return 0;
        else
            return INF;
    }
    
    if(dp[cnt][now] != -1) return dp[cnt][now];
    dp[cnt][now] = INF;
    
    for(int nxt : g[now]) {
        if(nxt == dest[cnt + 1])
            dp[cnt][now] = min(dp[cnt][now], dfs(cnt + 1, nxt));
        else
            dp[cnt][now] = min(dp[cnt][now], dfs(cnt + 1, nxt) + 1);
    }
    return dp[cnt][now];
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    answer = -1;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        g[i].push_back(i);
    }
    for(vector<int> e : edge_list) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    dest = gps_log;
    int ret = dfs(0, gps_log[0]);
    if(ret == INF) return -1;
    else return ret;
}