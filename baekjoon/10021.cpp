#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;
const int MN = 2001;
P arr[MN];
int p[MN];
bool vst[MN];

struct edge {
    int u, v, w;
};

void init(int N) {
    for(int i = 1; i <= N; i++)
        p[i] = i;
}

int find(int n) {
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

struct cmp {
    bool operator() (edge a, edge b) {
        return a.w > b.w;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, C; cin >> N >> C;
    priority_queue<edge, vector<edge>, cmp> pq;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
        for(int j = 1; j < i; j++) {
            int d = pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2);
            if(d >= C) {
                edge e = {i, j, d};
                pq.push(e);
            }
        }
    }
    init(N);
    int ans = 0, cnt = 0;
    while(cnt < N && !pq.empty()) {
        edge now = pq.top(); pq.pop();
        int pu = find(now.u), pv = find(now.v);
        if(pu == pv) continue;
        ans += now.w;
        p[pu] = now.v;
        if(!vst[now.u]) cnt++;
        if(!vst[now.v]) cnt++;
        vst[now.u] = true, vst[now.v] = true;
    }
    if(cnt == N)
        cout << ans;
    else
        cout << -1;
}