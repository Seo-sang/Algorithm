#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A, B, C;

ll divNconq(ll a, ll b) {
    if(b == 0) return 1;
    if(b % 2) return divNconq(a, b - 1) * a % C;
    else {
        ll tmp = divNconq(a, b / 2);
        return tmp * tmp % C;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> A >> B >> C;
    cout << divNconq(A, B);
}