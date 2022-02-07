#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 1e9 + 1;
const int MOD = 1e9 + 7;

ll f(ll n) {
    if(n == 0) return 1;
    if(n % 2)
        return f(n - 1) * 2 % MOD;
    else {
        ll tmp = f(n / 2);
        return tmp * tmp % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;

    while(T--) {
        ll N; cin >> N;
        if(N == 1) {
            cout << 1 << '\n';
            continue;
        }
        cout << f(N - 2) << '\n';
    }
}