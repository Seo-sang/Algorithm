#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
const int MN = 10001;
const ll INF = 1e15;

vector<P> g[MN];
ll dist[21][MN];

struct node {
    int u;
    ll w;
    int d;
};

struct cmp {
    bool operator() (node a, node b) {
        return a.w > b.w;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    fill(&dist[0][0], &dist[20][MN], INF);
    dist[0][1] = 0;
    priority_queue<node, vector<node>, cmp> q; q.push({1, 0, 0});
    while(!q.empty()) {
        node now = q.top(); q.pop();
        if(dist[now.d][now.u] < now.w) continue;
        for(P nxt : g[now.u]) {
            if(dist[now.d][nxt.second] > now.w + nxt.first) {
                dist[now.d][nxt.second] = now.w + nxt.first;
                q.push({nxt.second, dist[now.d][nxt.second], now.d});
            }
            if(now.d + 1 <= K && dist[now.d + 1][nxt.second] > now.w) {
                dist[now.d + 1][nxt.second] = now.w;
                q.push({nxt.second, dist[now.d + 1][nxt.second], now.d + 1});
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i <= K; i++)
        ans = min(ans, dist[i][N]);
    cout << ans;
}