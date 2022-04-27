#include <bits/stdc++.h>

using namespace std;
const int MN = 300001;
vector<int> g[MN];
int D, G;

vector<int> dfs(int now, int prev) {
    int n = g[now].size();
    if(n >= 3) G += (n * (n - 1) * (n - 2) / 6);
    vector<int> ret(4, 0);
    vector<int> child(4, 0);
    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        vector<int> tmp = dfs(nxt, now);
        ret[2] += tmp[1];
        ret[3] += tmp[2];
        D += (tmp[1] * child[2]);
        D += (tmp[2] * child[1]);
        D += tmp[3];
        child[1]++;
        child[2] += tmp[2];
    }
    ret[1] = 1;

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i= 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    if(D > G * 3) cout << "D\n";
    else if(D < G * 3) cout << "G\n";
    else cout << "DUDUDUNGA\n";
}