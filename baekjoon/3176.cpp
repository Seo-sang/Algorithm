#include <iostream>
#include <vector>

using namespace std;

const int MN = 100001;
struct edge{
    int w, v;
};
int h[MN];
vector<edge> g[MN];
edge dp[20][MN];

void dfs(int n, int prev) {
    for(edge next : g[n]) {
        if(next.v == prev) continue;
        h[next.v] = h[n] + 1;
        dfs(next.v, n);
        dp[0][next.v].v = n;
        dp[0][next.v].w = next.w;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N -1; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    dfs(1, 0);
    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j].w =
        }
    }

    int K; cin >> K;
    while(K--) {
        int D, E; cin >> D >> E;

    }
}