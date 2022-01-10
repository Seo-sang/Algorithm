#include <iostream>
#include <vector>

using namespace std;

const int MN = 1001;

vector<int> g[MN];
bool visit[MN];

void dfs(int n) {
    for(int e : g[n]) {
        if(visit[e]) continue;
        visit[e] = true;
        dfs(e);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    int ans = 0;
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        if(visit[i]) continue;
        ans++;
        visit[i] = true;
        dfs(i);
    }

    cout << ans;
}