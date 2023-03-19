#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 10001;
vector<P> g[MN];

bool vst[MN];
int d = 0;
int start;

void dfs(int now, int prev, int dist) {
    if(d < dist) {
        d = dist;
        start = now;
    }
    for(P nxt : g[now]) {
        if(nxt.second == prev) continue;
        dfs(nxt.second, now, dist + nxt.first);
    }
}

int main() {
    int a, b, w;
    while(cin >> a >> b >> w) {
        g[a].push_back(make_pair(w, b));
        g[b].push_back(make_pair(w, a));
    }
    dfs(1, 0, 0);

    d = 0;
    dfs(start, 0, 0);
    cout << d;

}