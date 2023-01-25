#include <bits/stdc++.h>

using namespace std;

const int MN = 500001;
int arr[MN];
int seg[MN * 3];
int lazy[MN * 3];

void init(int node, int start, int end) {
    if(start == end) {
        seg[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

void update_lazy(int node, int start, int end) {
    if(lazy[node]) {
        if((end - start + 1) % 2) {
            seg[node] ^= lazy[node];
        }
        if(start != end) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;

    }
}

void update(int node, int start, int end, int left, int right, int value) {
    update_lazy(node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right) {
        if((end - start + 1) % 2) {
            seg[node] ^= value;
        }
        if(start != end) {
            lazy[node * 2] ^= value;
            lazy[node * 2 + 1] ^= value;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);

    seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) ^ query(node *  2 + 1, mid + 1, end, left, right);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    init(1, 0, N - 1);

    cin >> M;
    while(M--) {
        int q, i, j, k;
        cin >> q >> i >> j;
        if(q == 1) {
            cin >> k;
            update(1, 0, N - 1, i, j, k);
        }
        else cout << query(1, 0, N - 1, i, j) << '\n';

    }
}
