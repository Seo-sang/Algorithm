#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 250001;
const int MM = 65536;

int arr[MN + 1];
int seg[(MM + 1) * 3];

int update(int node, int start, int end, int pos, int value) {
    if(pos < start || end < pos) return seg[node];
    if(start == end) return seg[node] += value;

    int mid = (start + end) / 2;
    return seg[node] = update(node * 2, start, mid, pos, value) + update(node * 2 + 1, mid + 1, end, pos, value);
}

int query(int node, int start, int end, int value) {
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(seg[node * 2] >= value) return query(node * 2, start, mid, value);
    else return query(node * 2 + 1, mid + 1, end, value - seg[node * 2]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;

    for(int i = 0; i < K; i++) {
        cin >> arr[i];
        update(1, 0, MM, arr[i], 1);
    }
    ll ans = query(1, 0, MM , (K + 1) / 2);

    for(int i = K; i < N; i++) {
        cin >> arr[i];
        update(1, 0, MM, arr[i], 1);
        update(1, 0, MM, arr[i - K], -1);
        int ret = query(1, 0, MM, (K + 1 )/ 2);
        ans += ret;
    }

    cout << ans;

}