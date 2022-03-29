#include <bits/stdc++.h>
#define ll long long
#define P pair<long long, long long>
using namespace std;
const int MN = 200001;
const ll INF = 1e15;
ll dist[MN];
vector<P> g[MN];
vector<int> path[MN];
bool note[MN];
int sum;
vector<int> ans;

bool dfs(int now, int prev, int cnt) {
    if(now == 1) {
        if(cnt == sum) {
            ans.push_back(now);
            return true;
        }
        return false;
    }
    for(int parent : path[now]) {
        if(parent == prev) continue;
        int nxtcnt = cnt;
        if(note[parent]) nxtcnt = cnt + 1;
        if(dfs(parent, now, nxtcnt)) {
            ans.push_back(now);
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        ll u, v; ll w; cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
        g[v].push_back(make_pair(w, u));
    }
    for(int i = 1; i <= N; i++) {
        cin >> note[i];
        if(note[i]) sum++;
    }
    
    priority_queue<P, vector<P>, greater<P> > pq;
    fill(dist, dist + N + 1, INF);
    dist[1] = 0;
    pq.push(make_pair(0, 1));

    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        if(dist[now.second] < now.first) continue;

        for(P nxt : g[now.second]) {
            if(dist[nxt.second] > now.first + nxt.first) {
                dist[nxt.second] = now.first + nxt.first;
                path[nxt.second].clear();
                path[nxt.second].push_back(now.second);
                pq.push(make_pair(dist[nxt.second], nxt.second));
            }
            else if(dist[nxt.second] == now.first + nxt.first)
                path[nxt.second].push_back(now.second);
        }
    }
    if(note[N])
        dfs(N, 0, 1);
    else
        dfs(N, 0, 0);
    
    if(ans.size() == 0)
        cout << -1;
    else {
        cout << ans.size() << '\n';
        for(int e : ans)
            cout << e << ' ';
    }
    
}