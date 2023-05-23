#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MN = 1e6 + 1;
ll seg[MN * 3];

ll update(int node, int left, int right, int pos, ll value) {
    if(pos < left || right < pos) return seg[node];
    if(left == right) return seg[node] += value;

    int mid = (left + right) / 2;
    ll l = update(node * 2, left, mid, pos, value);
    ll r = update(node * 2 + 1, mid + 1, right, pos, value);

    return seg[node] = l + r;
}

ll query(int node, int left, int right, int start, int end) {
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return seg[node];
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N >> Q;

    while(Q--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) update(1, 1, N, b, (ll)c);
        else cout << query(1, 1, N, b, (ll)c) << '\n';
    }
}