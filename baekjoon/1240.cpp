#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
vector<pair<int,int> > g[MN];
bool visit[MN];
int a, b;

int dfs(int n) {
    for(pair<int,int> e : g[n]) {
        if(visit[e.first]) continue;
        visit[e.first] = true;
        if(e.first == b) return e.second;
        int ret = dfs(e.first);
        if(ret != 0) {
            return ret + e.second;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 0;  i< N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }

    while(M--) {
        memset(visit, 0, sizeof(visit));
        cin >> a >> b;
        visit[a] = true;
        cout << dfs(a) << '\n';
    }
}