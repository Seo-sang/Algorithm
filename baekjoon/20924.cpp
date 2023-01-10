#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 200001;
vector<P> g[MN];
bool vst[MN];

int pilow = 0;

int findPilow(int now, int prev) {
    int cnt = 0, ret = now;
    for(P nxt : g[now]) {
        if(nxt.second == prev) continue;
        cnt++;
        if(cnt >= 2)
            return now;
    }
    for(P nxt : g[now]) {
        if(nxt.second == prev) continue;
        pilow += nxt.first;
        ret = findPilow(nxt.second, now);
    }
    vst[now] = true;
    return ret;
}

int findBranch(int now) {
    int ret = 0;
    for(P nxt : g[now]) {
        if(vst[nxt.second]) continue;
        vst[nxt.second] = true;
        ret = max(ret, findBranch(nxt.second) + nxt.first);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, R; cin >> N >> R;
    for(int i = 0; i < N -1 ; i++) {
        int a, b, d; cin >> a >> b >> d;
        g[a].push_back(make_pair(d, b));
        g[b].push_back(make_pair(d, a));
    }
    vst[R] = true;
    int giga = findPilow(R, 0);
    vst[giga] = true;
    cout << pilow << ' ' << findBranch(giga);
}