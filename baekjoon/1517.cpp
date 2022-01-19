#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MN = 500001;
int arr[MN];
int tmp[MN];

long long ans = 0;

void merge(int start1, int end1, int start2, int end2) {
    int idx1 = start1, idx2 = start2;
    int idx = start1;
    while(idx1 <= end1 && idx2 <= end2) {
        if(arr[idx1] <= arr[idx2]) {
            tmp[idx++] = arr[idx1++];
        }
        else {
            ans += abs(idx2 - idx);
            tmp[idx++] = arr[idx2++];
        }
    }
    while(idx1 <= end1) {
        tmp[idx++] = arr[idx1++];
    }
    while(idx2 <= end2) {
        tmp[idx++] = arr[idx2++];
    }
    memcpy(arr + start1, tmp + start1, sizeof(int) * (end2 - start1 + 1));
}


void mergesort(int start, int end) {
    if(start >= end) return;
    int mid = (start + end) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);

    merge(start, mid, mid + 1, end);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> arr[i];

    mergesort(0, N-1);

    cout << ans;
}