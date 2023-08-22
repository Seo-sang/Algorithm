#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
vector<int> g[MN];
int vst[MN];
int cycle[MN];

int dfs(int now, int prev, int cnt) {
    vst[now] = cnt;
    int ret = cnt;

    for(int nxt : g[now]) {
        if(prev == nxt) continue;
        if(!vst[nxt]) {
            int nxtcnt = dfs(nxt, now, cnt + 1);
            if(nxtcnt <= vst[now]) cycle[now]++;
            ret = min(ret, nxtcnt);
        }
        else {
            if(vst[nxt] <= vst[now]) cycle[now]++;
            ret = min(ret, vst[nxt]);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N >> M;

    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        if(!vst[i]) dfs(1, 0, 1);
    }

    bool chk = false;
    for(int i = 1; i <= N; i++) {
        // cout << i << ' ' << cycle[i] << endl;
        if(cycle[i] > 1) {
            chk = true;
        }
    }
    if(!chk) cout << "Cactus";
    else cout << "Not cactus";
}