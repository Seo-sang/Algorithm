#include <bits/stdc++.h>

using namespace std;

const int MN = 100001;
int arr[MN];
int seg[MN * 6];

int update(int node, int start, int end, int pos, int value) {
    if(pos < start || end < pos) return seg[node];
    if(start == end) return seg[node] = value;
    int mid = (start + end) / 2;
    return seg[node] = update(node * 2, start, mid, pos, value) + update(node * 2 + 1, mid + 1, end, pos, value);
}

int query(int node, int start, int end,  int left, int right) {
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(arr, 0, sizeof(arr));
        memset(seg, 0, sizeof(seg));
        int N, M; cin >> N >> M;
        for(int i = 1; i <= N; i++) {
            arr[i] = N - i;
            update(1, 0, N + M - 1, arr[i], 1);
        }
        
        for(int i = 1; i <= M; i++) {
            int a; cin >> a;
            cout << query(1, 0, N + M - 1, arr[a] + 1, N + M - 1) << ' ';
            update(1, 0, N + M - 1, arr[a], 0);
            update(1, 0, N + M - 1, N + i - 1, 1);
            arr[a] = N + i - 1;
        }
        

        cout << '\n';
    }
}