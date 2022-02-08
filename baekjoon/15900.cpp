#include <bits/stdc++.h>

using namespace std;
const int MN = 500001;
vector<int> g[MN];
int h[MN];
int height;
void dfs(int n, int prev) {
    int cnt = 0;
    for(int e : g[n]) {
        if(e == prev) continue;
        h[e] = h[n] + 1;
        cnt++;
        dfs(e, n);
    }
    if(cnt == 0)
        height += h[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
   }
    dfs(1, 0);
    if(height % 2) cout << "Yes";
    else cout << "No";
}