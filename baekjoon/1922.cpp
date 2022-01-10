#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 1001;
struct e {
    int w, u, v;
};

vector<e> edge;
int p[MN];
int visit[MN];

bool cmp(e a, e b) {
    return a.w < b.w;
}

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

void initialize(int N) {
    while(N--) p[N] = N;
}

int main() {
    int N, M; cin >> N >> M;
    initialize(N);

    for(int i = 0; i < M; i++) {
        int a, b, w; cin >> a >> b >> w;
        if(a == b) continue;
        edge.push_back({w, a, b});
    }
    sort(edge.begin(), edge.end(), cmp);

    int ans = 0;
    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w; 
        int fu = find(u);
        int fv = find(v);
        if(fu == fv) continue;
        ans += w;
        p[fu] = fv;
    }

    cout << ans;
}