#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 100001;
int p[MN];
pair<int,int> query[MN];
bool in[MN];
vector<int> rem;
ll nodes[MN];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        nodes[i] = 1;
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
    nodes[x] += nodes[y];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, Q; cin >> N >> M >> Q;

    init(N);

    for(int i = 1; i <= M; i++) {
        int x, y; cin >> x >> y;
        query[i] = make_pair(x, y);
    }

    while(Q--) {
        int a; cin >> a;
        in[a] = true;
        rem.push_back(a);
    }

    ll ans = 0;
    for(int i = 1; i <= M; i++) {
        if(!in[i]) {
            int x = query[i].first;
            int y = query[i].second;
            if(find(x) != find(y))
                unite(x, y);
        }
    }
    reverse(rem.begin(), rem.end());

    for(int e : rem) {
        int x = query[e].first;
        int y = query[e].second;
        if(find(x) != find(y)) {
            ans += nodes[find(x)] * nodes[find(y)];
            unite(x, y);
        }
    }

    cout << ans;
    
}