#include <iostream>
using namespace std;
#define ll long long
#define MN 1010101

ll seg[MN*3];
ll update(ll L, ll R, ll val, int n, int l, int r) {
    if(r < L || R < l) return seg[n];
    if(l == r) return seg[n] += val;
    int mid = (l + r) / 2;
    return seg[n] = update(L, R, val, n*2, l, mid) + update(L, R, val, n*2+1, mid+1, r);
}

ll query(ll L, ll R, int n, int l, int r) {
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return seg[n];
    int mid = (l + r) / 2;
    return query(L, R, n*2, l, mid) + query(L, R, n*2+1, mid+1, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K;    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        ll a;  cin >> a;
        update(i, i, a, 1, 1, N);
    }

    int T = M + K;
    while(T--) {
        int a; cin >> a;
        ll b, c, d;
        
        if(a == 1) {
            cin >> b >> c >> d;
            update(b, c, d, 1, 1, N);
        }
        else {
            cin >> b >> c;
            cout << query(b, c, 1, 1, N) << '\n';
        }
    }
    return 0;
}