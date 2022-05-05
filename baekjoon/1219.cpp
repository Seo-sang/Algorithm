#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long

using namespace std;
const int MN = 51, INF = 1e9;
vector<P> g[MN];
int cost[MN];
bool vst[MN];
ll dist[MN];

bool cycle(int s, int e) {
    vst[s] = true;
    if(s == e) return true;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(P nxt : g[now]) {
            if(vst[nxt.second]) continue;
            if(nxt.second == e) return true;
            vst[nxt.second] = true;
            q.push(nxt.second);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, A, B, M; cin >> N >> A >> B >> M;
    fill(dist, dist + N, -INF);
    for(int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
        
    }
    for(int i = 0; i < N; i++) cin >> cost[i];
     dist[A] = cost[A];
    bool ans = false;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < N; j++) {
            if(dist[j] == -INF) continue;
            for(P nxt : g[j]) {
                if(i < N)
                    dist[nxt.second] = max(dist[nxt.second], dist[j] - nxt.first + cost[nxt.second]);
                else {
                    if(dist[nxt.second] < dist[j] - nxt.first + cost[nxt.second]) {
                        if(cycle(nxt.second, B)) ans = true;
                    }
                }
            }
        }
    }
    if(dist[B] == -INF) cout << "gg\n";
    else if(ans) cout << "Gee\n";
    else cout << dist[B] << '\n';
}