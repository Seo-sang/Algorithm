#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 10001;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN];

int main() {
    int N, D; cin >> N >> D;
    priority_queue<P, vector<P>, greater<P> > pq;

    for(int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a > D || b > D) continue;
        g[a].push_back(P(min(b - a, c), b));
    }
    fill(dist, dist + D + 1, INF);

    for(int i = 0; i <= D; i++) {
        g[i].push_back(P(1, i + 1));
    }
    pq.push(P(0, 0));
    dist[0] = 0;

    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        if(dist[now.second] < now.first) continue;
        for(P nxt : g[now.second]) {
            if(dist[nxt.second] > dist[now.second] + nxt.first) {
                dist[nxt.second] = dist[now.second] + nxt.first;
                pq.push(make_pair(dist[nxt.second], nxt.second));
            }
        }
    }

    cout << dist[D];


}