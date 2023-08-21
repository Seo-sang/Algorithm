#include <bits/stdc++.h>

using namespace std;

const int MN = 10001;
vector<int> g[MN];
bool ans[MN];
int vst[MN];
int V, E;

int dfs(int now, int prev, int cnt, bool isroot) {
    vst[now] = cnt;
    int res = cnt;
    int child = 0;

    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        if(!vst[nxt]) {
            int nxtcnt = dfs(nxt, now, cnt + 1, false);
            child++;
            if(!isroot && (nxtcnt >= vst[now])) ans[now] = true;
            res = min(res, nxtcnt);
        }
        else res = min(res, vst[nxt]);
    }
    if(isroot && (child > 1)) ans[now] = true;

    return res;
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
        if(!vst[i]) dfs(i, 0, 1, true);
    }

    int cnt = 0;
    for(int i = 1; i <= V; i++) {
        if(ans[i]) cnt++;
    }
    cout << cnt << '\n';
    for(int i = 1; i <= V; i++) {
        if(ans[i]) cout << i << ' ';
    }

}