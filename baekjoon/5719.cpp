#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 501;
const int INF = 1e9;
vector<P> g[MN];
vector<int> path[MN];
int dist[MN];
int S, D;
int mnum; 
bool broken[MN][MN];

int dfs(int now, int cost) {
    if(now == D) {
        if(mnum > cost) {
            memset(broken, 0, sizeof(broken));
            mnum = cost;
        }
        return cost;
    }

    int ret = INF;
    for(P nxt : g[now]) {
        if(cost + nxt.first <= dist[nxt.second]) {
            dist[nxt.second] = cost + nxt.first;
            int tmp = dfs(nxt.second, dist[nxt.second]);
            if(tmp == mnum) broken[now][nxt.second] = true;
            ret = min(ret, tmp);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M;
    while(true) {
        cin >> N >> M;
        fill(dist, dist + N, INF);
        if(N == 0 && M == 0) break;
        cin >> S >> D;
        for(int i = 0; i < MN; i++) {
            g[i].clear();
            path[i].clear();
        }

        while(M--) {
            int u, v, p; cin >> u >> v >> p;
            g[u].push_back(make_pair(p, v));
        }

        priority_queue<P, vector<P>, greater<P> > pq;
        // pq.push({0, S});
        // dist[S] = 0;

        // while(!pq.empty()) {
        //     P now =pq.top(); pq.pop();
        //     if(dist[now.second] > now.first) continue;
        //     for(P nxt : g[now.second]) {
        //         if(dist[nxt.second] > now.first + nxt.first) {
        //             dist[nxt.second] = now.first + nxt.first;
        //             path[nxt.second].clear();
        //             path[nxt.second].push_back(now.second);
        //             pq.push({dist[nxt.second], nxt.second});
        //         }
        //         else if(dist[nxt.second] == now.first + nxt.first)
        //             path[nxt.second].push_back(now.second);
        //     }
        // }
        int tmp = dist[D];
        memset(broken, 0, sizeof(broken));
        mnum = INF;
        dist[S] = 0;
        dfs(S, 0);
        
        fill(dist, dist + N, INF);
        pq.push({0, S});
        dist[S] = 0;

        while(!pq.empty()) {
            P now =pq.top(); pq.pop();
            if(dist[now.second] > now.first) continue;
            for(P nxt : g[now.second]) {
                if(broken[now.second][nxt.second]) continue;
                if(dist[nxt.second] > now.first + nxt.first) {
                    dist[nxt.second] = now.first + nxt.first;
                    pq.push({dist[nxt.second], nxt.second});
                }
            }
        }
        
        cout << ((dist[D] == INF) ? -1 : dist[D]) << '\n';
    }
}