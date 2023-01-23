#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 100001;
vector<P> g[MN];
int dist[MN];

int dfs(int now, int prev, int d, int exclude) {
    int ret = now;
    for(P nxt : g[now]) {
        if(nxt.second == prev || nxt.second == exclude) continue;
        int tmp = dfs(nxt.second, now, d + nxt.first, exclude);
        if(dist[ret] < dist[tmp]) ret = tmp;
    }
    dist[now] = d;
    return ret;
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
        g[b].push_back(make_pair(c, a));
    }
    int start = dfs(1, 0, 0, -1);
    memset(dist, 0, sizeof(dist));
    int end = dfs(start, 0, 0, -1);
    memset(dist, 0, sizeof(dist));
    int ans1 = dist[dfs(start, 0, 0, end)];
    memset(dist, 0, sizeof(dist));
    int ans2 = dist[dfs(end, 0, 0, start)];
    cout << max(ans1, ans2);
}