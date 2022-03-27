#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 200001;
const int INF = 1e9;
int arr[MN];
int dist[MN];
int way[MN];
int mindist = INF;
int found = INF + 1;

bool note[MN], vst[MN];
vector<P> g[MN];

struct edge {
    int w, v, cnt;
};

struct cmp {
    bool operator() (edge& a, edge& b) {
        return a.w < b.w;
    }
};
vector<int> v;
void dfs(int n) {
    if(n == 0) return;
    v.push_back(n);
    dfs(way[n]);
}

int main() {
    int N, M; cin >> N >> M;
    fill(dist, dist + N + 1, INF);
    while(M--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }
    int sum = 0;
    for(int i = 1;  i <= N; i++) {
        cin >> note[i];
        if(note[i]) sum++;
    }

    priority_queue<edge , vector<edge>, cmp> pq;
    int a = note[1] ? 1 : 0;
    pq.push({0, 1, a});
    dist[1] = 0;
    while(!pq.empty()) {
        edge now = pq.top(); pq.pop();
        for(P nxt : g[now.v]) {
            if(dist[nxt.first] >= now.cnt + nxt.second) {
                dist[nxt.first] = now.cnt + nxt.second;
                way[nxt.first] = now.v;
                int tmpcnt = note[nxt.first] ? (now.cnt + 1) : now.cnt;
                if(nxt.first == N)
                    mindist = min(mindist, dist[nxt.first]);
                if(nxt.first == N && tmpcnt == sum) {
                    dfs(N);
                    found = dist[nxt.first];
                }
                pq.push({dist[nxt.first], nxt.first, tmpcnt});
            }
        }
    }
    
    if(mindist == found) {
        cout << v.size() << '\n';
        for(int i = 0; i < v.size() - 1; i++)
            cout << v[i] << ' ';
        cout << v.back();
    }
    else
        cout << -1;
}