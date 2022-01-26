#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 10001;
int arr[MN];
int N, M;

ll f(int mid) {
    ll ret = 0;
    for(int i = 0; i < M; i++)
        ret += (arr[i] / mid);

    return ret;
}
int main() {
    cin >> N >> M;
    ll lo = 31, hi;
    for(int i = 0; i < M; i++) {
        cin >> arr[i];
        lo = min(lo, arr[i]);
    }
    lo--;
    hi = lo * N;

    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        ll ret = f(mid);
        if(ret < N - 1) lo = mid;
        else hi = mid;
    }
    cout << hi << endl;

    for(int i = 0; i < M; i++) {
        if(arr[i] % hi == 0) {
            cout << i + 1;
            break;
        }
    }
}