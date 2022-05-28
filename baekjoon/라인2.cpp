#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

const int MN = 2001;
const int INF = 1e9;
int N;
int dp[MN];

//줄 개수, 소요 시간
int dfs(int now, int cnt, vector<int>& times) {
    if(now > N) return INF;
    if(dp[now] != -1 && dp[now] <= cnt) return dp[now];
    if(now == N) return dp[now] = cnt;
    int &ret = dp[now];
    ret = INF;
    for(int i = 0; i < times.size(); i++) {
        if(now < i + 1) continue;
        ret = min(ret, dfs(now + i + 1, cnt + times[i], times));
    }

    return ret;
}

int solution(int n, vector<int> times) {
    int answer = 0;
    N = n;
    memset(dp, -1, sizeof(dp));
    return dfs(1, 0, times);
}