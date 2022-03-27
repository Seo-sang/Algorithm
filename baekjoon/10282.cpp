#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 10001;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        fill(dist, dist + MN, INF);
        for(int i = 0;  i < MN; i++)
            g[i].clear();

        int N, D, C; cin >> N >> D >> C;
        priority_queue<P, vector<P>, greater<P> > pq;
        while(D--) {
            int a, b, s; cin >> a >> b >> s;
            g[b].push_back(make_pair(s, a));
        }
        pq.push(make_pair(0, C));
        dist[C] = 0;
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
        int mnum = 0;
        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            if(dist[i] != INF) {
                cnt++;
                mnum = max(mnum, dist[i]);
            }
        }
        cout << cnt << ' ' << mnum << '\n';
    }
}