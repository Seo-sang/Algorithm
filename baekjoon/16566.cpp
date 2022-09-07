#include <bits/stdc++.h>

using namespace std;
const int MN = 4000001;
int card[MN], p[MN];

int find(int u) {
    if(p[u] == u) return u;
    return p[u] = find(p[u]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    p[a] = b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        cin >> card[i];
        p[i] = i;
    }
    sort(card, card + M);
    for(int i = 0; i < K; i++) {
        int a; cin >> a;
        int idx = find(upper_bound(card, card + M, a) - card);
        cout << card[idx] << '\n';
        join(idx, idx + 1);
    }
}