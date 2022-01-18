#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e9;
const int MN = 1001;

#define P pair<int,int>

int dist[MN];
int go[MN];
vector<P> g[MN];

int main() {
    int N, M, X; cin >> N >> M >> X;
    while(M--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({w, v});
    }
    int ans = 0;

    for(int i = 1; i <= N; i++) {
        priority_queue<P, vector<P>, greater<P>> pq;
        fill(&dist[0], &dist[N + 1], INF);
        pq.push({0, i});
        dist[i] = 0;
        while(!pq.empty()) {
            P now = pq.top(); pq.pop();
            int pos = now.second;
            int w = now.first;
            for(P e : g[pos]) {
                if(dist[e.second] > w + e.first) {
                    dist[e.second] = w + e.first;
                    pq.push({dist[e.second], e.second});
                }
            }
        }
        if(i == X) {
            for(int i = 1; i <= N; i++)
                go[i] += dist[i];
        }
        go[i] += dist[X];
    }

    for(int i = 1; i <= N; i++)
        ans = max(ans, go[i]);

    cout << ans;
}