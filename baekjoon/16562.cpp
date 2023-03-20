#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 10001;
vector<P> cost;
vector<int> g[MN];
bool vst[MN];

int main() {
    int N, M, K; cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        cost.push_back(make_pair(a, i + 1));
    }
    while(M--) {
        int v, w; cin >> v >> w;
        g[v].push_back(w);
        g[w].push_back(v);
    }
    sort(cost.begin(), cost.end());
    int price = 0;

    for(P now : cost) {
        if(vst[now.second]) continue;
        vst[now.second] = true;
        price += now.first;
        queue<int> q;
        q.push(now.second);
        while(!q.empty()) {
            int f = q.front(); q.pop();
            for(int nxt : g[f]) {
                if(vst[nxt]) continue;
                vst[nxt] = true;
                q.push(nxt);
            }
        }
    }

    if(price <= K) cout << price;
    else cout << "Oh no";


}