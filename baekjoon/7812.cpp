#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 10001;
const int INF = 101;
vector<P> g[MN];
int dp[MN];

vector<P> dfs(int now, int prev) {
    vector<P> ret;
    for(P nxt : g[now]) {
        if(prev == nxt.second) continue;
        vector<P> tmp = dfs(nxt.second, now);
        for(P e : tmp) {
            dp[now] += (e.first + nxt.first);
            dp[e.second] += (e.first + nxt.first);
            ret.push_back(make_pair(e.first + nxt.first, now));
            cout << e.first + nxt.first << endl;
        }
        dp[now] += nxt.first;
        dp[nxt.second] += nxt.first;
        ret.push_back(make_pair(nxt.first, now));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    while(true) {
        int ans = 1e9;
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++) {
            g[i].clear();
        }

        for(int i = 0; i < N - 1; i++) {
            int a, b, w; cin >> a >> b >> w;
            g[a].push_back(make_pair(w, b));
            g[b].push_back(make_pair(w, a));
        }
        memset(dp, 0, sizeof(dp));
        dfs(0, -1);

        for(int i = 0; i < N; i++)
            ans = min(ans, dp[i]);

        cout << ans << '\n';
    }
}