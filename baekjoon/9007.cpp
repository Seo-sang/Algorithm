#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> tmp, arr1, arr2;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int K, N, a; cin >> K >> N;
        arr1.clear();
        arr2.clear();
        tmp.clear();
        for(int i = 0; i < N; i++) {
            cin >> a;
            tmp.push_back(a);
        }
        for(int i = 0; i < N; i++) {
            cin >> a;
            for(ll e : tmp)
                arr1.push_back(e + a);
        }
        tmp.clear();
        for(int i = 0; i < N; i++) {
            cin >> a;
            tmp.push_back(a);
        }
        for(int i = 0; i < N; i++) {
            cin >> a;
            for(ll e : tmp)
                arr2.push_back(e + a);
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        ll ans = arr1[0] + arr2[0], gap;
        for(ll e : arr1) {
            int idx = lower_bound(arr2.begin(), arr2.end(), abs(K - e)) - arr2.begin();
            if(0 <= idx && idx < arr2.size()) {
                gap = abs(K - ans);
                ll tmp = abs(K - (arr2[idx] + e));
                if(gap > tmp) ans = arr2[idx] + e;
                if(gap == tmp) ans = min(ans, arr2[idx] + e);
            }
            idx--;
            if(0 <= idx && idx < arr2.size()) {
                gap = abs(K - ans);
                ll tmp = abs(K - (arr2[idx] + e));
                if(gap > tmp) ans = arr2[idx] + e;
                if(gap == tmp) ans = min(ans, arr2[idx] + e);
            }
        }

        cout << ans << '\n';
    }
}