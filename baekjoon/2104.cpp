#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 100001;
ll arr[MN];

ll divNconq(int s, int e) {
    if(s == e) return arr[s] * arr[s];
    int mid = (s + e) / 2;
    ll ret = max(divNconq(s, mid), divNconq(mid + 1, e));
    int l = mid, r = mid + 1;
    ll width = arr[l] + arr[r];
    ll h = min(arr[l], arr[r]);
    ret = max(ret, h * width);

    while(s < l || r < e) {
        if(s == l) {
            width += arr[++r];
            h = min(h, arr[r]);
        }
        else if(r == e) {
            width += arr[--l];
            h = min(h, arr[l]);
        }
        else if(arr[l - 1] > arr[r + 1]) {
            width += arr[--l];
            h = min(h, arr[l]);
        }
        else {
            width += arr[++r];
            h = min(h, arr[r]);
        }

        ret = max(ret, width * h);
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