#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
const int INF = 1e9;
int maxseg[MN * 3];
int minseg[MN * 3];

int maxupdate(int node, int start, int end, int pos, int value) {
    if(pos < start || end < pos) return maxseg[node];
    if(start == end) return maxseg[node] = value;
    int mid = (start + end) / 2;
    return maxseg[node] = max(maxupdate(node * 2, start, mid, pos, value), maxupdate(node * 2 + 1, mid + 1, end, pos, value));
}

int minupdate(int node, int start, int end, int pos, int value) {
    if(pos < start || end < pos) return minseg[node];
    if(start == end) return minseg[node] = value;
    int mid = (start + end) / 2;
    return minseg[node] = min(minupdate(node * 2, start, mid, pos, value), minupdate(node * 2 + 1, mid + 1, end, pos, value));
}

int maxquery(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return maxseg[node];
    int mid = (start + end) / 2;
    return max(maxquery(node * 2, start, mid, left, right), maxquery(node * 2 + 1, mid + 1, end, left, right));
}
int minquery(int node, int start, int end, int left, int right) {
    if(right < start || end < left) return INF;
    if(left <= start && end <= right) return minseg[node];
    int mid = (start + end) / 2;
    return min(minquery(node * 2, start, mid, left, right), minquery(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        maxupdate(1, 1, N, i, a);
        minupdate(1, 1, N, i, a);
    }
    while(M--) {
        int a, b; cin >>a >> b;
        if(a > b) swap(a, b);
        cout << minquery(1, 1, N, a, b) << ' ' << maxquery(1, 1, N, a, b) << '\n';
    }
}