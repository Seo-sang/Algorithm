#include <bits/stdc++.h>

using namespace std;
const int MN = 200001;
map<string, int> m;
int p[MN];
int f[MN];
int idx = 1;

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;

    while(T--) {
        int F; cin >> F;
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));
        idx = 1;
        m.clear();
        while(F--) {
            string a, b; cin >> a >> b;
            if(m.find(a) == m.end()) {
                m[a] = idx++;
                f[idx-1] = 1;
                p[idx-1] = idx-1;
            }
            if(m.find(b) == m.end()) {
                m[b] = idx++;
                f[idx-1] = 1;
                p[idx-1] = idx-1;
            }
            int aidx = find(m[a]);
            int bidx = find(m[b]);
            if(aidx == bidx) {
                cout << f[bidx] << '\n';
                continue;
            }
            f[bidx] += f[aidx];
            p[aidx] = bidx;
            cout << f[bidx] << '\n';
        }
    }
}