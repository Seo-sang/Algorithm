#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
int arr[MN], ans[MN];
int seg[MN * 3];

int update(int n, int left, int right, int pos) {
    if(pos < left || right < pos) return seg[n];
    if(left == right) return seg[n] = 1;
    int mid = (left + right) / 2;
    return seg[n] = update(n * 2, left, mid, pos) + update(n * 2 + 1, mid + 1, right, pos);
}

int query(int n, int left, int right, int start, int end) {
    if(right < start || end < left) return 0;
    if(start <= left && right <= end) return right - left + 1 - seg[n];
    if(left == right) return !seg[n];
    int mid = (left + right) / 2;
    return query(n * 2, left, mid, start, end) + query(n * 2 + 1, mid + 1, right, start, end);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    for(int i = N; i > 0; i--) {
        int left = 0, right = N + 1;
        while(left + 1 < right) {
            int mid = (left + right) / 2;
            int ret = query(1, 1, N, mid, N);
            if(ret >= arr[i] + 1) left = mid;
            else right = mid;
        }
        ans[left] = i;
        update(1, 1, N, left);
    }
    for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
}