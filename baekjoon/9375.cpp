#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int main() {
    int T; cin >> T;
    while(T--) {
        m.clear();
        int N; cin >> N;
        for(int i = 0; i < N; i++) {
            string s1, s2; cin >> s1 >> s2;
            m[s2]++;
        }
        int ans = 1;
        for(auto it = m.begin(); it != m.end(); it++)
            ans *= (it->second + 1);
        cout << ans - 1 << '\n';
    }
}