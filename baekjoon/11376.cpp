#include <bits/stdc++.h>

using namespace std;

const int MN = 2002;
vector<int> g[MN];
int p[MN];
bool visited[MN];

bool dfs(int n) {
    for(int nxt : g[n]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        if(p[nxt] == -1 || dfs(p[nxt])) {
            p[nxt] = n;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    M += 1000;
    for(int i = 1; i <= N; i++) {
        int n; cin >> n;
        while(n--) {
            int w; cin >> w;
            w += 1000;
            g[i].push_back(w);
        }
    }
    memset(p, -1, sizeof(p));
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 2; j++) {
            memset(visited, 0, sizeof(visited));
            dfs(i);
        }
    }
    int ans = 0;
    for(int i = 1001; i <= M; i++) {
        if(p[i] != -1) ans++;
    }
    cout << ans;
}