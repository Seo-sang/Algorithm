#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
const int INF = 1e9;
int seg[MN * 3];

int update(int node, int start, int end, int pos, int value) {
    if(pos < start || end < pos) return seg[node];
    if(start == end) return seg[node] = value;
    int mid = (start + end) / 2;
    return seg[node] = min(update(node * 2, start, mid, pos, value), update(node * 2 + 1, mid + 1, end, pos, value));
}

int query(int node, int start, int end, int left, int right) {
    if(end < left || right < start) return INF;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    fill(&seg[0], &seg[MN], INF);
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        update(1, 1, N, i, a);
    }
    while(M--) {
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        cout << query(1, 1, N, a, b) << '\n';
    }
}