#include <iostream>
#include <vector>

using namespace std;

const int MN = 100001;
int parent[MN];
vector<int> g[MN];

void dfs(int n) {
    for(int e : g[n]) {
        if(parent[e]) continue;
        parent[e] = n;
        dfs(e);
    }
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    parent[1] = 1;
    dfs(1);
    for(int i = 2; i <= N; i++)
        cout << parent[i] << '\n';
}