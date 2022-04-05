#include <bits/stdc++.h>
#define PP pair<int,int>

using namespace std;
const int MN = 1001;
const int INF = 1e9;
vector<PP> g[MN];
int dist[MN];
int N, P, K;

bool dijkstra(int limit) {
    priority_queue<PP, vector<PP>, greater<PP> > pq;
    fill(dist, dist + N + 1, INF);
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    while(!pq.empty()) {
        PP now = pq.top(); pq.pop();
        if(dist[now.second] < now.first) continue;
        for(PP nxt : g[now.second]) {
            int nxtCost = (limit < nxt.first ? now.first + 1 : now.first);
            if(dist[nxt.second] > nxtCost) {
                dist[nxt.second] = nxtCost;
                pq.push(make_pair(dist[nxt.second], nxt.second));
            }
        }
    }

    return dist[N] <= K;
}

int main() {
    cin >> N >> P >> K;
    while(P--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
        g[v].push_back(make_pair(w, u));
    }
    int left = 0, right = 1e6 + 1;
    int ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(dijkstra(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans;

}