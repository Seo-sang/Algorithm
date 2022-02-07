#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

ll divNconq(ll A, ll X) {
    if(X == 0) return 1;
    if(X % 2) return divNconq(A, X - 1) * A % MOD;
    else {
        ll tmp = divNconq(A, X / 2);
        return tmp * tmp % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll A, X; cin >> A >> X;
    cout << divNconq(A % MOD, X);
}