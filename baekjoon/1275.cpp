#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MN = 100001;
int arr[MN];
ll seg[MN * 3];

ll init(int node, int start, int end) {
    if(start == end) return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll update(int node, int start, int end, int pos, ll value) {
    if(pos < start || end < pos) return seg[node];
    if(start == end) return seg[node] = value;
    int mid = (start + end) / 2;

    return seg[node] = update(node * 2, start, mid, pos, value) + update(node * 2 + 1, mid + 1, end, pos, value);
}

ll query(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(start >= left && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N >> Q;
    for(int i = 0 ; i < N; i++)
        cin >> arr[i];
    init(1, 0, N-1);

    while(Q--) {
        ll x, y, a, b; cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        cout << query(1, 0, N-1, x - 1, y - 1) << '\n';
        update(1, 0, N-1, a - 1, b);
    }
}