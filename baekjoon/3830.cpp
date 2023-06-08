#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;

int p[MN], weight[MN];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        weight[i] = 0;
    }
}

int find(int n) {
    if(p[n] == n) {
        weight[n] = 0;
        return n;
    }
    int pn = find(p[n]);
    weight[n] += weight[p[n]];
    return p[n] = pn;
}

void unite(int a, int b, int w) {
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return;

    weight[pb] = weight[a] - weight[b] + w;
    p[pb] = pa;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        init(N);
        while(M--) {
            char c; cin >> c;
            int a, b, w;
            if(c == '!') {
                cin >> a >> b >> w;
                unite(a, b, w);
            }
            else {
                cin >> a >> b;
                if(find(a) != find(b)) cout << "UNKNOWN\n";
                else cout << weight[b] - weight[a] << '\n';
            }
        }
    }
}