#include <bits/stdc++.h>
#define ll long long
#define mat vector<vector<ll>>
using namespace std;

const int MN = 1e8 + 1;

mat mul(mat a, mat b) {
    mat c(a.size(), vector<ll>(b[0].size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b[0].size(); j++) {
            for(int k = 0; k < b.size(); k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= 100;
            }
        }
    }
    return c;
}

mat pow(mat a, int n) {
    if(n == 1) return a;
    if(n % 2) return mul(pow(a, n - 1), a);
    mat ret = pow(a, n / 2);
    return mul(ret, ret);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll x, y, a0, a1, N; cin >> x >> y >> a0 >> a1 >> N;

    if(N == 0) {
        if(a0 < 10)
            cout << 0;
        cout << a0;
        return 0;
    }
    else if(N == 1) {
        if(a1 < 10)
            cout << 0;
        cout << a1;
        return 0;
    }

    mat A(2, vector<ll> (2, 0));
    A[0][0] = x, A[0][1] = y, A[1][0] = 1, A[1][1] = 0;
    A = pow(A, N - 1);
    mat B(2, vector<ll> (1, 0));
    B[0][0] = a1, B[1][0] = a0;

    B = mul(A, B);
    if(B[0][0] < 10)
        cout << 0;
    cout << B[0][0];
}