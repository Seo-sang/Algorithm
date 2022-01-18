#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define P pair<int,int>
using namespace std;
const int MN = 20001;
const int INF = 1e9;

int dist[MN];
vector<P> g[MN];

int main() {
    int V, E; cin >> V >> E;
    int K; cin >> K;
    for(int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    fill(&dist[0], &dist[V+1], INF);
    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        for(P e : g[now.second]) {
            if(dist[e.second] > now.first + e.first) {
                dist[e.second] = now.first + e.first;
                pq.push({dist[e.second], e.second});
            }
        }
    }

    for(int i = 1; i <= V; i++)
        dist[i] == INF ?  cout << "INF\n" : cout << dist[i] << '\n';
}