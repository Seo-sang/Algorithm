#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
const int INF = 1e9 + 1;
int seg[MN * 3];
int arr[MN];

int update(int node, int left, int right, int pos, int value) {
    if(pos < left || right < pos) return seg[node];
    if(left == right) {
        arr[pos] = value;
        return seg[node] = pos;
    }
    int mid = (left + right) / 2;
    int l = update(node * 2, left, mid, pos, value);
    int r = update(node * 2 + 1, mid + 1, right, pos, value);
    if(arr[l] <= arr[r])
        return seg[node] = l;
    else 
        return seg[node] = r;
}

int query(int node, int left, int right, int start, int end) {
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return seg[node];
    int mid = (left + right) / 2;
    int l = query(node * 2, left, mid, start, end);
    int r = query(node * 2 + 1, mid + 1, right, start, end);
    if(arr[l] <= arr[r])
        return l;
    else
        return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    fill(&arr[0], &arr[N + 1], INF + 1);

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(1, 1, N, i, arr[i]);
    }

    int M; cin >> M;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) update(1, 1, N, b, c);
        else cout << query(1, 1, N, b, c) << '\n';
    }
}