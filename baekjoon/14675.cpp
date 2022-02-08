#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
vector<int> g[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int q; cin >> q;
    while(q--) {
        int t, k; cin >> t >> k;
        if(t == 1) {
            if(g[k].size() == 1) cout << "no\n";
            else cout << "yes\n";
        }
        else {
            cout << "yes\n";
        }
    }
}