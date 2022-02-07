#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 1e6 + 1;
const int MM = 1e3 + 1;

ll rest[MM];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    ll sum = 0;
    for(int i = 1; i <= N; i++) {
        ll a; cin >> a;
        sum += a;
        rest[sum % M]++;
    }
    ll ans = 0;
    for(int i = 0; i < M; i++) {
        if(rest[i] == 0) continue;
        ans += (rest[i] * (rest[i] - 1) / 2);
        for(int j = i + 1; j < M; j++) {
            if((j - i) % M == 0) {
                ans += (rest[i] * rest[j]);
            }
        }
    }
    ans += rest[0];
    cout << ans;
}