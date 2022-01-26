#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 10001;
int arr[MN];
int N, M;

ll f(int mid) {
    ll ret = 0;
    for(int i = 0; i < M; i++)
        ret += (mid / arr[i]);

    return ret;
}
int main() {

    cin >> N >> M;
    int lo = 31, hi = 0;
    for(int i = 0; i < M; i++) {
        cin >> arr[i];
        lo = min(lo, arr[i]);
        hi = max(hi, arr[i]);
    }
    lo--;
    hi = hi * N;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        ll ret = f(mid);
        //cout << mid << ' ' << ret << endl;
        if(ret < N - 1) lo = mid;
        else hi = mid;
    }

    cout << hi << endl;
    bool chk = false;
    for(int i = M -1; i >= 0; i--) {
        cout << N << ' ' << hi / arr[i] << endl;
        if(hi % arr[i] == 0) {
            cout << (i + 1) % M + 1;
            break;
        }
    }
}