#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 50001;
const int INF = 1e9;
vector<P> g[MN];
int dp[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    fill(&dp[0], &dp[MN], INF);
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
        g[b].push_back(make_pair(c, a));
    }
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(make_pair(0, 1));
    dp[1] = 0;
    while(!q.empty()) {
        P now = q.top(); q.pop();
        if(now.first > dp[now.second]) continue;
        for(P nxt : g[now.second]) {
            if(dp[nxt.second] > now.first + nxt.first) {
                dp[nxt.second] = now.first + nxt.first;
                q.push(make_pair(dp[nxt.second], nxt.second));
            }
        }
    }

    cout << dp[N];
}