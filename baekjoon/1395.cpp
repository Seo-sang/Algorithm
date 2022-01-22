#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
int seg[MN * 3];
int lazy[MN * 3];

void lazy_update(int node, int start, int end) {
    if(lazy[node]) {
        seg[node] = end - start + 1 - seg[node];
        if(start != end) {
            lazy[node * 2] = (lazy[node * 2] ? 0 : 1);
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] ? 0 : 1);
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right) {
    lazy_update(node, start, end);
    if(left > end || right < start) return;

    if(left <= start && end <= right) {
        seg[node] = end - start + 1 - seg[node];
        if(start != end) {
            lazy[node * 2] = (lazy[node * 2] ? 0 : 1);
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] ? 0 : 1);
        }
        return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right);
    update(node * 2 + 1, mid + 1, end, left, right);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
    lazy_update(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int O, S, T; cin >> O >> S >> T;
        if(O)
            cout << query(1, 0, N-1, S - 1, T - 1) << '\n';
        else
            update(1, 0, N-1, S - 1, T - 1);
    }
}