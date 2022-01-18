#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
const int MM = 1000001;

struct edge{
    int w, u, v;
};

int p[MN];
edge arr[MM];

void init(int n) {
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    int cnt = N;
    for(int i = 0; i < M; i++)
        cin >> arr[i].u >> arr[i].v >> arr[i].w;

    sort(arr, arr + M, cmp);

    init(N);

    int ans = 0;
    for(int i = 0;  i < M; i++) {
        edge now = arr[i];
        if(find(now.u) == find(now.v)) continue;
        p[find(now.u)] = now.v;
        ans += now.w;
        cnt--;
        if(cnt == 2) break;
    }

    cout << ans;
}