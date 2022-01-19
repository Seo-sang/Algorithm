#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MN = 1e15 + 1;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll N, K, Q; cin >> N >> K >> Q;
    vector<int> v;
    while(Q--) {
        ll a, b; cin >> a >> b;
        if(K == 1) {
            cout << abs(a -b) << '\n';
            continue;
        }
        a--, b--;
        if(a < b) swap(a, b);
        v.clear();
        while(a > 0) {
            a--;
            a /= K;
            v.push_back(a);
        }
        int level = 0;
        while(b >= 0) {
            auto it = find(v.begin(), v.end(), b);
            if(it != v.end()) {
                level += ((it - v.begin()) + 1);
                break;
            }
            b--;
            b /= K;
            level++;
        }

        cout << level << '\n';
    }
}