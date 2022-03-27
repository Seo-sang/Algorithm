#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int INF = 1e9;
const int MN = 300001;
vector<int> g[MN];
int dist[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K, X; cin >> N >> M >> K >> X;
    while(M--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    fill(dist, dist + N + 1, INF);

    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(make_pair(0, X));
    dist[X] = 0;
    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        for(int nxt : g[now.second]) {
            if(dist[nxt] > dist[now.second] + now.first) {
                dist[nxt] = dist[now.second] + 1;
                pq.push(make_pair(dist[nxt], nxt));
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(dist[i] == K) {
            cnt++;
            cout << i << '\n';
        }
    }
    if(!cnt)
        cout << -1;
}