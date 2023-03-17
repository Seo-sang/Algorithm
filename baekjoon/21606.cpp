#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 200001;
vector<int> g[MN];
bool vst[MN];

string A;


ll dfs(int now, int prev) {
    if(A[now] == '1') return 1;
    vst[now] = true;
    ll ret = 0;
    for(int nxt : g[now]) {
        if(nxt == prev || vst[nxt]) continue;
        ret += dfs(nxt, now);
    }

    return ret;
}

int main() {
    int N; cin >> N;
    cin >> A;
    A = "0" + A;
    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        if(vst[i]) continue;
        if(A[i] == '0') {
            int ret = dfs(i, 0);
            ans += ret * (ret - 1);
        }
        else {
            for(int nxt : g[i]) {
                
                if(A[nxt] == '1') {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}