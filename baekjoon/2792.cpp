#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MM = 300001;
int arr[MM];
int N, M; 

ll f(ll mid) {
    ll ret = 0;
    for(int i = 0; i < M; i++) {
        ret += arr[i] / mid;
        if(arr[i] % mid) ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    ll lo = 0, hi = 0;
    for(int i = 0; i < M; i++) {
        cin >> arr[i];
        hi += arr[i];
    }

    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        //cout << lo << ' ' << hi << endl;
        ll ret = f(mid);
        if(ret > N) lo = mid;
        else hi = mid;
    }
    cout << hi;

}