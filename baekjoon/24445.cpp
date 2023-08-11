#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
vector<int> g[MN];
int ans[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, R; cin >> N >> M >> R;
    while(M--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= N; i++)
        sort(g[i].begin(), g[i].end(), greater<int>());

    queue<int> q;
    q.push(R);
    int cnt = 2;
    ans[R] = 1;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int nxt : g[now]) {
            if(ans[nxt]) continue;
            ans[nxt] = cnt++;
            q.push(nxt);
        }
    }
    for(int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}