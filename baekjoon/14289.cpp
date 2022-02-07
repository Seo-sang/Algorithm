#include <bits/stdc++.h>
#define ll long long
#define mat vector<vector<ll>>

using namespace std;

const ll MOD = 1e9 + 7;

mat mul(mat a, mat b) {
    mat c (a.size(), vector<ll> (b[0].size(), 0));
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

mat pow(mat a, int n) {
    if(n == 1) return a;
    if(n % 2)
        return mul(pow(a, n - 1), a);
    mat ret = pow(a, n / 2);
    return mul(ret, ret);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;

    mat arr(N, vector<ll>(N, 0));

    while(M--) {
        int a, b; cin >> a >> b;
        a--, b--;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    int D; cin >> D;
    
    arr = pow(arr, D);

    cout << arr[0][0];
}