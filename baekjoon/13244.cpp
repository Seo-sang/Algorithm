#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
vector<int> g[MN];
bool vst[MN];

bool dfs(int now, int prev) {
    bool ret = true;
    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        if(vst[nxt]) return false;
        vst[nxt] = true;
        ret &= dfs(nxt, now);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(vst, 0, sizeof(vst));
        for(int i = 0; i < MN; i++) g[i].clear();

        int N, M; cin >> N >> M;
        while(M--) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vst[1] = true;
        if(!dfs(1, 0)) cout << "graph\n";
        else {
            string ans = "tree\n";
            for(int i = 1; i <= N; i++) {
                if(!vst[i]) {
                    ans = "graph\n";
                    break;
                }
            }
            cout << ans;
        }
    }
}