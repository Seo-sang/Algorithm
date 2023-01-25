#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
vector<int> seg[MN * 3];

void init(int node, int start, int end, int pos, int value) {
    if(pos < start || end < pos) return;
    seg[node].push_back(value);
    if(start == end) return;

    int mid = (start + end) / 2;
    init(node * 2, start, mid, pos, value);
    init(node * 2 + 1, mid + 1, end, pos, value);
}


int query(int node, int start, int end, int left, int right, int k) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) {
        auto it = upper_bound(seg[node].begin(), seg[node].end(), k);
        return (seg[node].end() - it);
    }

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right, k) + query(node * 2 + 1, mid + 1 , end, left, right, k);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N;
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        init(1, 1, N, i, a);
    }

    for(int i = 1; i < MN * 3; i++)
        sort(seg[i].begin(), seg[i].end());
    
    cin >> M;
    while(M--) {
        int i, j, k; cin >> i >> j >> k;
        cout << query(1, 1, N, i, j, k) << '\n';
    }
    
}