#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 1000001;
int arr[MN];
int tmp[MN];
ll ans;
void merge(int s1, int e1, int s2, int e2) {
    int idx1 = s1, idx2 = s2;
    int idx = s1;
    while(idx1 <= e1 && idx2 <= e2) {
        if(arr[idx1] > arr[idx2]) {
            tmp[idx++] = arr[idx2++];
            ans += (ll)(e1 - idx1 + 1);
        }
        else {
            tmp[idx++] = arr[idx1++];
        }
    }
    while(idx1 <= e1) {
        tmp[idx++] = arr[idx1++];
    }

    while(idx2 <= e2) {
        tmp[idx++] = arr[idx2++];
    }
    memcpy(arr + s1, tmp + s1, sizeof(int) * (e2 - s1 + 1));
}

void mergesort(int start, int end) {
    if(start == end) return;
    int mid = (start + end) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);

    merge(start, mid, mid + 1, end);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) 
        cin >> arr[i];

    mergesort(1, N);

    cout << ans;
}