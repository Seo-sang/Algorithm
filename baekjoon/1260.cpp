#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MN = 1001;
vector<int> g[MN];
bool visit[MN];

void dfs(int V) {
    cout << V << ' ';
    for(int e : g[V]) {
        if(visit[e]) continue;
        visit[e] = true;
        dfs(e);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, V; cin >> N >> M >> V;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
        sort(g[i].begin(), g[i].end());

    visit[V] = true;
    dfs(V);
    cout << '\n';

    memset(visit, 0, sizeof(visit));
    visit[V] = true;
    queue<int> q;
    q.push(V);
    cout << V << ' ';
    while(!q.empty()) {
        int now = q.front(); q.pop();

        for(int e : g[now]) {
            if(visit[e]) continue;
            visit[e] = true;
            cout << e << ' ';
            q.push(e);
        }
    }

    cout << '\n';
}