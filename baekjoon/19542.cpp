#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
vector<int> g[MN];
int del[MN];
int N, S, D;
int ans = 0;

int dfs(int now, int prev) {
    //말단 노드인 경우
    if(prev != 0 && g[now].size() == 1) {
        del[now] = 0;
        return 1;
    }
    int ret = 0;
    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        ret = max(ret, dfs(nxt, now));
    }
    del[now] = ret;
    return ret + 1;
}

void dfs2(int now, int prev) {
    //cout << now << endl;
    for(int nxt : g[now]) {
        if(nxt == prev || D > del[nxt]) continue;
        ans++;
        dfs2(nxt, now);
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> S >> D;
    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(S, 0);

    dfs2(S, 0);
    cout << ans;
}