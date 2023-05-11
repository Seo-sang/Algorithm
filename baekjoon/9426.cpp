#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MN = 250001;
const int MM = 65536;
int arr[MN];
int seg[MM * 3];

void update(int n, int pos, int left, int right, int value) {
    if(left == right) {
        seg[n] += value;
        return;
    }

    int mid = (left + right) / 2;

    if(pos <= mid) update(n * 2, pos, left, mid, value);
    else update(n * 2 + 1, pos, mid + 1, right, value);

    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int query(int n, int cnt, int left, int right) {
    if(left == right) return left;

    int mid = (left + right) / 2;

    if(seg[n * 2] >= cnt) return query(n * 2, cnt, left, mid);
    else return query(n * 2 + 1, cnt - seg[n * 2], mid + 1, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, K; cin >> N >> K;
    ll ans = 0;

    for(int i = 0; i < K - 1; i++) {
        cin >> arr[i];
        update(1, arr[i], 0, MM - 1, 1);
    }
    for(int i = K - 1; i < N; i++) {
        cin >> arr[i];
        update(1, arr[i], 0, MM - 1, 1);
        ans += query(1, (K + 1) / 2, 0, MM - 1);
        update(1, arr[i - K + 1], 0, MM - 1, -1);
    }

    cout << ans;

}