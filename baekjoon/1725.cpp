#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 100001;
ll arr[MN];

ll divNconq(int start, int end) {
    if(start == end) return arr[start];
    int mid = (start + end) / 2;
    ll ret = max(divNconq(start, mid), divNconq(mid + 1, end));
    int l = mid, r = mid + 1;
    ll h = min(arr[l], arr[r]);
    ret = max(ret, h * (r - l + 1));

    while(start < l || r < end) {
        if(l == start) h = min(h, arr[++r]);
        else if(r == end) h = min(h, arr[--l]);
        else if(arr[l - 1] > arr[r + 1]) h = min(h, arr[--l]);
        else h = min(h, arr[++r]);

        ret = max(ret, h * (r - l + 1));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    cout << divNconq(0, N - 1);
}