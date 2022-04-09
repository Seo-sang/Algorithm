#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
const int MN = 100001;
const int MOD = 1e9 + 7;
vector<P> g[MN];
vector<ll> dp[MN];
ll ans;

vector<ll> dfs(int n, int prev) {
    vector<ll> ret;
    vector<vector<ll> > child;
    for(P nxt : g[n]) {
        if(nxt.second == prev) continue;
        vector<ll> tmp = dfs(nxt.second, n);
        for(ll e :tmp) {
            ret.push_back((e * nxt.first) % MOD);
            ans += ret.back();
        }
        tmp.push_back(nxt.first);
        child.push_back(tmp);

        ret.push_back(nxt.first);
        ans += nxt.first;
    }
    if(child.size()) {
        for(int i = 0; i < child.size() - 1; i++) {
            for(int j = i + 1; j < child.size(); j++) {
                for(ll a : child[i]) {
                    for(ll b : child[j]) {
                        ans += ((a * b) % MOD);
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back(make_pair(w, b));
        g[b].push_back(make_pair(w, a));
    }
    dfs(1, 0);
    cout << ans;
}