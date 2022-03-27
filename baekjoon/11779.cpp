#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 1001;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN];
int path[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    fill(dist ,dist + N + 1, INF);

    while(M--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
    }
    int start, end; cin >> start >> end;

    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        if(dist[now.second] < now.first) continue;
        for(P nxt : g[now.second]) {
            if(dist[nxt.second] > dist[now.second] + nxt.first) {
                dist[nxt.second] = dist[now.second] + nxt.first;
                pq.push(make_pair(dist[nxt.second], nxt.second));
                path[nxt.second] = now.second;
            }
        }
    }

    vector<int> ans;
    ans.push_back(end);
    int now = end;
    while(now != start) {
        ans.push_back(now = path[now]);
    }
    cout << dist[end] << '\n';
    cout << ans.size() << '\n';
    for(auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << ' ';
}