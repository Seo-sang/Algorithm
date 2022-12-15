#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 1001;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN];
int dp[MN];

int dfs(int now) {
    if(now == 2) return 1;
    if(dp[now] != 0) return dp[now];
    dp[now] = 0;
    for(P nxt : g[now]) {
        if(dist[nxt.second] < dist[now])
            dp[now] += dfs(nxt.second);
    }

    return dp[now];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
        g[b].push_back(make_pair(c, a));
    }
    fill(&dist[1], &dist[N + 1], INF);
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(make_pair(0, 2));
    dist[2] = 0;
    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        if(dist[now.second] < now.first) continue;
        for(P nxt : g[now.second]) {
            if(dist[nxt.second] > now.first + nxt.first) {
                dist[nxt.second] = now.first + nxt.first;
                pq.push(make_pair(dist[nxt.second], nxt.second));
            }
        }
    }
    cout << dfs(1);
}