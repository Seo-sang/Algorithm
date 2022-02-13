#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 1000001;
const int MOD = 1e9 + 7;
ll seg[MN];

ll update(int node, int start, int end, int pos, ll value) {
    if(pos < start || end < pos) return seg[node];
    if(start == end) return seg[node] = value;
    int mid = (start + end) / 2;
    return seg[node] = (update(node * 2, start, mid, pos, value) * update(node * 2 + 1, mid + 1, end, pos, value)) % MOD;
}

ll query(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 1LL;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        ll a; cin >> a;
        update(1, 1, N, i, a);
    }
    M += K;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1)
            update(1, 1, N, b, (ll)c);
        else {
            if(b > c) swap(b, c);
            cout << query(1, 1, N, b, c) << '\n';
        }
    }
}