#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 10001;
ll arr[MN];
ll N, M;

ll f(ll mid) {
    ll ret = 0;
    for(int i = 0; i < M; i++)
        ret += (mid / arr[i] + 1);

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    ll lo = -1LL, hi = 0;
    for(int i = 0; i < M; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }
    lo = -1LL;
    hi = hi * N;

    if(N <= M) {
        cout << N;
        return 0;
    }
    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll ret = f(mid);
        if(ret < N) lo = mid;
        else hi = mid;
    }

    ll ans = 0;
    ll remain = N - f(hi - 1);
    for(int i = 0; i < M; i++) {
        if(remain == 0) break;
        if(hi % arr[i] == 0) remain--;
        ans = i;
    }

    cout << ans + 1;
}