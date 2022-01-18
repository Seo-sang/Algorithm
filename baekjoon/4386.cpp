#include <bits/stdc++.h>

using namespace std;

#define P pair<double,double>
const int MN = 101;
P arr[MN];
int p[MN];

struct edge {
    double w;
    int u, v;
};
vector<edge> v;

double dist(P a, P b) {
    double aa = abs(a.first - b.first);
    double bb = abs(a.second - b.second);
    aa *= aa;
    bb *= bb;
    double ret = sqrt(aa + bb);

    return ret;
}

int find(int n) {
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        p[i] = i;
        cin >> arr[i].first >> arr[i].second;
        for(int j = 1; j < i; j++) {
            v.push_back({dist(arr[i], arr[j]), i, j});
        }
    }

    sort(v.begin(), v.end(), cmp);
    double ans = 0;

    for(edge e : v) {
        if(find(e.v) == find(e.u)) continue;
        p[find(e.v)] = e.u;
        ans += e.w;
    }

    cout.precision(2);
    cout << fixed;
    cout << ans;
}