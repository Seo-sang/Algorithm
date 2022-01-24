#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
const int INF = 1e9;
#define ll long long
ll T[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    ll mnum = 1e9;
    for(int i = 1; i <= N; i++) {
        cin >> T[i];
        mnum = min(mnum, T[i]);
    }

    ll lo = 0, hi = mnum * M;

    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for(int i = 1; i <= N; i++)
            cnt += (mid / T[i]);
 
        if(cnt < M) lo = mid;
        else hi = mid;
    }

    cout << hi;
}