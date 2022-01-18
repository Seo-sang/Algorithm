#include <bits/stdc++.h>

#define P pair<int,int>

using namespace std;
const int MN = 1001;

int p[MN];
pair<int,int> arr[MN];

struct edge {
    double w;
    int u, v;
};

vector<edge> road;

int find(int n) {
    if(p[n] == n) return n;
    else return p[n] = find(p[n]);
}

double dist(P a, P b) {
    double ret;
    long long aa = abs(a.first - b.first);
    long long bb = abs(a.second - b.second);
    ret = sqrt((double)aa*aa + bb*bb);

    return ret;
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        p[i] = i;
        cin >> arr[i].first >> arr[i].second;
        for(int j = 1; j < i; j++) {
            double d = dist(arr[i], arr[j]);
            road.push_back({d, i, j});
        }
    }

    while(M--) {
        int a, b; cin >> a >> b;
        if(find(a) != find(b))
            p[find(a)] = b;
    }

    sort(road.begin(), road.end(), cmp);
    double ans = 0;
    for(edge e : road) {
        if(find(e.u) == find(e.v)) continue;
        p[find(e.u)] = e.v;
        ans += e.w;
    }
    cout.precision(2);
    cout << fixed;
    cout << ans;
}