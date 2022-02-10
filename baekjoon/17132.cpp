#include <bits/stdc++.h>
#define P pair<int,int>
#define ll long long
using namespace std;
const int MN = 100001;
const int INF = 1e9;

int p[MN];
int group[MN];
struct edge {
    int x, y, w;
};
vector<edge> query;

void init(int N) {
    for(int i = 1; i <= N; i++) {
        p[i] = i;
        group[i] = 1;
    }
}

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);

    if(x > y) swap(x, y);
    p[y] = x;
    group[x] += group[y];
}

bool cmp(edge a, edge b) {
    return a.w > b.w;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    init(N);
    ll ans = 0;
    for(int i = 0; i < N - 1; i++) {
        int x, y, w; cin >> x >> y >> w;
        edge input = {x, y, w};
        query.push_back(input);
    }

    sort(query.begin(), query.end(), cmp);

    for(edge e : query) {
        ans += (ll)group[find(e.x)] * (ll)group[find(e.y)] * e.w;
        unite(e.x, e.y);
    }
    cout << ans;
}