#include <bits/stdc++.h>

using namespace std;
const int MN = 501;
vector<int> g[MN];
bool visited[MN];
bool isTree;

void dfs(int n, int prev) {
    for(int e : g[n]) {
        if(e == prev) continue;
        if(visited[e]) {
            isTree = false;
            continue;
        }
        visited[e] = true;
        dfs(e, n);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    int level = 1;
    while(true) {
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < MN; i++)
            g[i].clear();

        cin >> N >> M;
        if(N == 0 && M == 0) break;

        while(M--) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            if(visited[i]) continue;
            visited[i] = true;
            isTree = true;
            dfs(i, 0);
            if(isTree) ans++;
        }

        switch(ans) {
            case 0:
                cout <<"Case " << level++ << ": No trees.\n";
                break;
            case 1:
                cout <<"Case " << level++ <<  ": There is one tree.\n";
                break;
            default:
                cout <<"Case " <<level++ << ": A forest of " << ans << " trees.\n";
                break;
        }
    }
}