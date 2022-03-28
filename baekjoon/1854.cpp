#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int MN = 1001;
vector<P> g[MN];
priority_queue<int, vector<int>, less<int> > dist[MN];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
    }

    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(make_pair(0, 1));
    dist[1].push(0);

    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        for(P nxt : g[now.second]) {
            if(dist[nxt.second].size() < K) {
                dist[nxt.second].push(now.first + nxt.first);
                pq.push(make_pair(now.first + nxt.first, nxt.second));
            }
            else if(dist[nxt.second].top() > now.first + nxt.first) {
                dist[nxt.second].pop();
                dist[nxt.second].push(now.first + nxt.first);
                pq.push(make_pair(now.first + nxt.first, nxt.second));
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(dist[i].size() < K) cout << -1 << '\n';
        else {
            cout << dist[i].top() << '\n';
        }
    }
}