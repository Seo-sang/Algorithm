#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 201;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN];
int ans[MN][MN];

struct node {
    int u, w, s;
    node(int u, int w, int s) : u(u), w(w), s(s) {}
};

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
        g[v].push_back(make_pair(w, u));
    }
    for(int i = 1; i <= N; i++) {
        fill(&dist[0], &dist[MN], INF);
        dist[i] = 0;
        queue<node> q;
        for(P nxt : g[i]) {
            q.push(node(nxt.second, nxt.first, nxt.second));
            dist[nxt.second] = nxt.first;
            ans[i][nxt.second] = nxt.second;
        }
        while(!q.empty()) {
            node now = q.front(); q.pop();
            if(dist[now.u] < now.w) continue;
            for(P nxt : g[now.u]) {
                if(dist[nxt.second] > nxt.first + now.w) {
                    dist[nxt.second] = nxt.first + now.w;
                    q.push(node(nxt.second, dist[nxt.second], now.s));
                    ans[i][nxt.second] = now.s;
                }
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) cout << "- ";
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}