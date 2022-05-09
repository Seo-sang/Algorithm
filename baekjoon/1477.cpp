#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
int arr[MN];
int N, M, L;

int f(int mid) {
    int ret = 0, now = 0;
    for(int i = 0; i < N; i++) {
        ret += (arr[i] - now - 1) / mid;
        now = arr[i];
    }
    ret += (L - now - 1) / mid;

    return ret;
}

int main() {
    cin >> N >> M >> L;
    int left = 0, right = 1001;
    for(int i = 0; i < N; i++)
       cin >> arr[i];

    sort(arr, arr + N);

    while(left + 1 < right) {
        int mid = (left + right) / 2;
        if(f(mid) > M) left = mid;
        else right = mid;
    }
    cout << right;
}