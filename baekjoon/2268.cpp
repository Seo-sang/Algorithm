#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int MN = 1000001;
ll seg[MN * 3];

ll query(int node, int start, int end, int left, int right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

ll update(int node, int start, int end, int pos, ll value) {
    if(pos < start || end < pos) return seg[node];
    if(start == end) return seg[node] = value;
    int mid = (start + end) / 2;
    return seg[node] = update(node * 2, start, mid, pos, value) + update(node * 2 + 1, mid + 1, end, pos, value);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) {
            if(b > c)
                swap(b, c);
            cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
        else
            update(1, 0, N - 1, b - 1, (ll)c);
    }
}