#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
const int MN = 100001;
const int MOD = 1e9 + 7;
vector<P> g[MN];
ll ans;

ll dfs(int n, int prev) {
    ll ret = 1;
    vector<ll> rst;
    for(P nxt : g[n]) {
        if(nxt.second == prev) continue;
        ll tmp = dfs(nxt.second, n) * nxt.first % MOD;
        ans = (ans + tmp * ret) % MOD;
        ret = (ret + tmp) % MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back(make_pair(w, b));
        g[b].push_back(make_pair(w, a));
    }
    dfs(1, 0);
    cout << ans;
}