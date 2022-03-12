#include <bits/stdc++.h>

using namespace std;
const int MN = 1e5 + 1;
int plane[MN];
int p[MN];

int find(int n) {
    if(n == p[n]) return n;
    return p[n] = find(p[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int G, P; cin >> G >> P;
    int ans = 0;
    for(int i = 1; i <= G; i++)
        p[i] = i;
    for(int i = 0;  i < P; i++)
        cin >> plane[i];
    for(int i = 0; i < P; i++) {
        int n = find(plane[i]);
        if(n == 0) break;
        p[n] = n-1;
        ans++;
    }

    cout << ans;
}