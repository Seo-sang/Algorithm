#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 100001;
ll arr[MN];
ll seg[MN * 3];
ll lazy[MN * 3];

ll init(int node, int start, int end) {
    if(start == end) return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if(lazy[node]) {
        seg[node] += (end - start + 1) * lazy[node];

        if(start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, ll value) {
    update_lazy(node, start, end);

    if(right < start || end < left) return;

    if(left <= start && end <= right) {
        seg[node] += (end - start + 1) * value;

        if(start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }

    int mid = (start + end) / 2;

    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int start, int end, int pos) {
    update_lazy(node, start, end);
    if(pos < start || end < pos) return 0;
    if(start == end) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, pos) + query(node * 2 + 1, mid + 1, end, pos);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, 1, N);

    cin >> M;
    while(M--) {
        int q, i, j;
        ll k;
        cin >> q;
        if(q == 1) {
            cin >> i >> j >> k;
            update(1, 1, N, i, j, k);
        }
        else {
            cin >> i;
            cout << query(1, 1, N, i) << '\n';
        }
    }
}