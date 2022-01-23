#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
int arr[MN];
vector<int> seg[MN * 3];

void update(int node, int start, int end, int pos, int value) {
    if(pos < start || end < pos) return;
    if(start == end) {
        seg[node].push_back(value);
        return;
    }
    seg[node].push_back(value);
    int mid = (start + end) / 2;
    update(node * 2, start, mid, pos, value);
    update(node * 2 + 1, mid + 1, end, pos, value);
}

int query(int node, int start, int end, int left, int right, int value) {
    if(end < left || right < start) return 0;

    if(left <= start && end <= right) 
        return upper_bound(seg[node].begin(), seg[node].end(), value) - seg[node].begin();
    
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right, value) + query(node * 2 + 1, mid + 1, end, left, right, value);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        update(1, 0, N - 1, i, a);
    }

    for(int i = 0; i < MN * 3; i++)
        sort(seg[i].begin(), seg[i].end());

    while(M--) {
        int i, j, k; cin >> i >> j >> k;
        int l = -1e9, r = 1e9;
        while(l <= r) {
            int mid = (l + r) / 2;
            int rst = query(1, 0, N - 1, i - 1, j - 1, mid);
            if(rst < k) l = mid +1;
            else r = mid - 1;
        }

        cout << l << '\n';
    }
}