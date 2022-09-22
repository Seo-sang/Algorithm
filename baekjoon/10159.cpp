#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
vector<int> g[MN];
int cnt[MN];
bool vst[MN];

void dfs(int n, int start) {
    for(int nxt : g[n]) {
        if(vst[nxt]) continue;
        cnt[nxt]++;
        cnt[start]++;
        vst[nxt] = true;
        dfs(nxt, start);
    }
}

int main() {
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= N; i++) {
        memset(vst, 0, sizeof(vst));
        cnt[i]++;
        vst[i] = true;
        dfs(i, i);
    }

    for(int i = 1; i <= N; i++) {
        cout << N - cnt[i] << '\n';
    }
}