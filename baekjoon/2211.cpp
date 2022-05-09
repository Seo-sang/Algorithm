#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 1001;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN], path[MN];

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
        g[b].push_back(make_pair(c, a));
    }
    queue<P> q;
    q.push(make_pair(0, 1));
    fill(dist, dist + N + 1, INF);
    dist[1] = 0;
    while(!q.empty()) {
        P now = q.front(); q.pop();
        if(dist[now.second] < now.first) continue;
        for(P nxt : g[now.second]) {
            if(dist[nxt.second] > now.first + nxt.first) {
                dist[nxt.second] = now.first + nxt.first;
                path[nxt.second] = now.second;
                q.push(make_pair(dist[nxt.second], nxt.second));
            }
        }
    }
    cout << N - 1 << '\n';
    for(int i = 1; i <= N; i++)
        if(path[i])
            cout << i << ' ' << path[i] << '\n';
}