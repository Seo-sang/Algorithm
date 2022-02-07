#include <bits/stdc++.h>
#define ll long long
#define mat vector<vector<ll>>

using namespace std;

const int MOD = 1e6;

mat mul(mat a, mat b) {
    mat c(a.size(), vector<ll>(b[0].size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b[0].size(); j++) {
            for(int k = 0; k < b.size(); k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
        }
    }

    return c;
}

mat pow(mat a, ll n) {
    if(n == 1)
        return a;
    if(n % 2)
        return mul(pow(a, n - 1), a);
    mat ret = pow(a, n / 2);
    return mul(ret, ret);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll N; cin >> N;
    if(N == 1) {
        cout << "1\n";
        return 0;
    }
    mat A(2, vector<ll>(2, 0));
    mat B(2, vector<ll>(1, 0));
    A[0][0] = A[0][1] = A[1][0] = 1, A[1][1] = 0;
    B[0][0] = 1, B[1][0] = 0;

    A = pow(A, N - 1);
    B = mul(A, B);

    cout << B[0][0];
}