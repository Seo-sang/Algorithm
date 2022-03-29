#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 501;
const int INF = 1e9;
int g[MN][MN];
int dist[MN];
bool vst[MN];
vector<int> path[MN];
int N, M, S, D;

void dfs(int now, int nxt) {
    if(nxt == S) return;
    for(int e : path[now]) {
        g[e][now] = 0;
        if(vst[e]) continue;
        vst[e] = true;
        dfs(e, now);
    }
}

void dijkstra() {
    priority_queue<P, vector<P>, greater<P> > pq;
    fill(dist, dist + MN, INF);
    pq.push({0, S});
    dist[S] = 0;

    while(!pq.empty()) {
        P now =pq.top(); pq.pop();
        if(dist[now.second] > now.first) continue;
        for(int i = 0; i < N; i++) {
            if(g[now.second][i]) {
                if(dist[i] > now.first + g[now.second][i]) {
                    dist[i] = now.first + g[now.second][i];
                    path[i].clear();
                    path[i].push_back(now.second);
                    pq.push({dist[i], i});
                }
                else if(dist[i] == now.first + g[now.second][i])
                    path[i].push_back(now.second);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cin >> S >> D;
        memset(g, 0, sizeof(g));
        memset(vst, 0, sizeof(vst));
        for(int i = 0; i < MN; i++)
            path[i].clear();
        while(M--) {
            int u, v, p; cin >> u >> v >> p;
            g[u][v] = p;
        }
        dijkstra();
        vst[D] = true;
        dfs(D, -1);
        dijkstra();
        
        
        cout << ((dist[D] == INF) ? -1 : dist[D]) << '\n';
    }
}