#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 10001;
const int INF = 1e9;
vector<P> g[MN], rg[MN];
int dist[MN];
bool vst[MN];
int ans = 0;

struct node {
    int n, t, cnt;
    node(int a, int b, int c) : n(a), t(b), cnt(c) {}
};

struct cmp {
    bool operator() (node a, node b) {
        return a.t < b.t;
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
        rg[b].push_back(make_pair(c, a));
    }
    int start, end; cin >> start >> end;
    priority_queue<node, vector<node>, cmp> pq;

    dist[start] = 0;
    pq.push(node(start, 0, 0));
    int time = 0;
    while(!pq.empty()) {
        node now = pq.top(); pq.pop();
        time = max(time, now.t);
        for(P nxt : g[now.n]) {
            if(dist[nxt.second] < now.t + nxt.first) {
                dist[nxt.second] = now.t + nxt.first;
                pq.push(node(nxt.second, dist[nxt.second], now.cnt + 1));
            }
        }
    }
    vst[end] = true;

    queue<int> q;
    q.push(end);
    while(!q.empty()) {
        int now = q.front(); q.pop();

        for(P nxt : rg[now]) {
            if(dist[nxt.second] == dist[now] - nxt.first) {
                ans++;
                if(vst[nxt.second]) continue;
                vst[nxt.second] = true;
                q.push(nxt.second);
            }
        }
    }

    cout << time << '\n' << ans;
}