#include <iostream>
#include <vector>

using namespace std;
const int MN = 100001;

vector<int> g[MN];

int child[MN];

int dfs(int n, int prev) {
    int &ret = child[n];
    ret = 1;
    for(int e : g[n]) {
        if(e == prev) continue;
        ret += dfs(e, n);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, R, Q; cin >> N >> R >> Q;
    for(int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(R, 0);

    for(int i = 0; i < Q; i++) {
        int U; cin >> U;
        cout << child[U] << '\n';
    }

}