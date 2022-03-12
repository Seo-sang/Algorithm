#include <bits/stdc++.h>
#define ll long long
using namespace std;
multiset<ll> s;

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        ll a; cin >> a;
        s.insert(a);
    }
    while(M--) {
        auto it1 = s.begin(); s.erase(it1);
        auto it2 = s.begin(); s.erase(it2);
        ll sum = *it1 + *it2;
        s.insert(sum);
        s.insert(sum);
    }
    ll ans = 0;
    for(auto it = s.begin(); it != s.end(); it++)
        ans += *it;

    cout << ans;
}