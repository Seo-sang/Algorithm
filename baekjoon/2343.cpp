#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 100001;
int N;
ll arr[MN];

int f(ll n) {
    int ret = 1;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        if(sum + arr[i] <= n) sum += arr[i];
        else {
            ret++;
            sum = arr[i];
        }
    }
    return ret;
}

int main() {
    int M; cin >> N >> M;
    ll l = 0, r = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        r += arr[i];
        l = max(l, arr[i]);
    }
    l--;

    while(l + 1 < r) {
        ll mid = (l + r) / 2;
        int ret = f(mid);
        if(ret <= M) r = mid;
        else l = mid;
    }

    cout << r;
}