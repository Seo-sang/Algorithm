#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 100001;
vector<int> g[MN];
vector<pii> ans;
int vst[MN];

int V, E;

int dfs(int now, int prev, int cnt) {
    int ret = cnt;
    vst[now] = cnt;
    int child = 0;

    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        if(!vst[nxt]) {
            int nxtcnt = dfs(nxt, now, cnt + 1);
            if(nxtcnt >= vst[nxt]) ans.push_back(pii(min(now, nxt), max(now, nxt)));
            ret = min(ret, nxtcnt);

        }
        else ret = min(ret, vst[nxt]);
    }


    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V >> E;

    while(E--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    for(int i = 1; i <= V; i++) {
        if(!vst[i]) dfs(i, 0, 1);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(pii e : ans) cout << e.first << ' ' << e.second << '\n';
}