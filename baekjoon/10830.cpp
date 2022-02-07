#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MN = 6;
const int MOD = 1e3;
int N;
ll arr[MN][MN];
ll l[MN][MN];
ll r[MN][MN];

void divNconq(ll B) {
    if(B == 1) {
        memcpy(l, arr, sizeof(l));
        return;
    }
    ll ret[MN][MN];
    memset(ret, 0, sizeof(ret));
    if(B % 2) {
        divNconq(B - 1);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    ret[i][j] += (l[i][k] * arr[k][j]);
                    ret[i][j] %= MOD;
                }
            }
        }

        memcpy(l, ret, sizeof(l));
    }
    else {
        divNconq(B / 2);
        memcpy(r, l, sizeof(r));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    ret[i][j] += (l[i][k] * r[k][j]);
                    ret[i][j] %= MOD;
                }
            }
        }

        memcpy(l, ret, sizeof(l));
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll B; cin >> N >> B;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            arr[i][j] %= MOD;
        }
    }

    divNconq(B);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << l[i][j] << ' ';
        }
        cout << '\n';
    }
}