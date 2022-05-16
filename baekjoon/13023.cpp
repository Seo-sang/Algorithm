#include <bits/stdc++.h>

using namespace std;
const int MN = 2001;
vector<int> g[MN];
bool vst[MN];

bool dfs(int n, int depth) {
    if(depth == 4) return true;
    bool ret = false;
    for(int nxt : g[n]) {
        if(vst[nxt]) continue;
        vst[nxt] = true;
        ret |= dfs(nxt, depth + 1);
        vst[nxt] = false;
        if(ret) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }   
    bool ans = false;
    for(int i = 0; i < N && !ans; i++) {
        vst[i] = true;
        ans |= dfs(i, 0);
        vst[i] = false;
    }
    cout << ans;
}