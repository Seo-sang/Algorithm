#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
struct pos{
    int idx, x, y, z;
};
struct edge {
    int w, u, v;
};

pos arr[MN];
vector<edge> v;
int p[MN];

int dist(pos a, pos b) {
    return min(abs(a.x - b.x), min(abs(a.y - b.y), abs(a.z - b.z)));
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

bool xcmp(pos a, pos b) {
    return a.x < b.x;
}
bool ycmp(pos a, pos b) {
    return a.y < b.y;
}
bool zcmp(pos a, pos b) {
    return a.z < b.z;
}

int find(int n) {
    if(n == p[n]) return n;
    else return p[n] = find(p[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        p[i] = i;
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
        arr[i].idx = i;
    }

    sort(arr + 1, arr + N + 1, xcmp);
    for(int i = 2; i <= N; i++)
        v.push_back({abs(arr[i].x - arr[i-1].x), arr[i].idx, arr[i-1].idx});

    sort(arr + 1, arr + N + 1, ycmp);
    for(int i = 2; i <= N; i++)
        v.push_back({abs(arr[i].y - arr[i-1].y), arr[i].idx, arr[i-1].idx});

    sort(arr + 1, arr + N + 1, zcmp);
    for(int i = 2; i <= N; i++)
        v.push_back({abs(arr[i].z - arr[i-1].z), arr[i].idx, arr[i-1].idx});
    
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    
    for(edge e : v) {
        if(find(e.u) == find(e.v)) continue;
        p[find(e.u)] = e.v;
        ans += e.w;
    }

    cout << ans;

}