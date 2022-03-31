#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 5001;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN][MN];
bool vst[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N - 1; i++) {
        int p, q, r; cin >> p >> q >> r;
        g[p].push_back(make_pair(r, q));
        g[q].push_back(make_pair(r, p));
    }
    
    for(int i = 1; i <= N; i++) {
        memset(vst, 0, sizeof(vst));
        queue<P> q; q.push(make_pair(INF, i));
        vst[i] = true;
        while(!q.empty()) {
            P now = q.front(); q.pop();
            for(P nxt : g[now.second]) {
                if(vst[nxt.second]) continue;
                vst[nxt.second] = true;
                dist[i][nxt.second] = min(now.first, nxt.first);
                q.push(make_pair(dist[i][nxt.second], nxt.second));
            }
        }
        dist[i][i] = 0;
    }

    while(Q--) {
        int k, v; cin >> k >> v;
        int ans = 0;
        for(int i = 1; i <= N; i++)
            if(dist[v][i] >= k) ans++;

        cout << ans << '\n';
    }
}