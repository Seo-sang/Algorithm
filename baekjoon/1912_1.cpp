#include <bits/stdc++.h>

using namespace std;

//divNconq로 풀기
const int MN = 100001;
int arr[MN];

int divNconq(int s, int e) {
    if(s == e) return arr[s];
    int mid = (s + e) / 2;
    int ret = max(divNconq(s, mid), divNconq(mid + 1, e));
    int l = -1000, r = -1000;
    int sum = 0;
    for(int i = mid; i >= s; i--) {
        sum += arr[i];
        l = max(l, sum);
    }

    sum = 0;
    for(int i = mid + 1; i <= e; i++) {
        sum += arr[i];
        r = max(r, sum);
    }

    ret = max(ret, l + r);

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    cout << divNconq(0, N - 1);
}