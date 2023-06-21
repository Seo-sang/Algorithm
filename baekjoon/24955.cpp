#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 1001;
const int MOD = 1e9 + 7;

string A[MN];
vector<int> g[MN];

string dfs(int now, int prev, int dest) {
    if(now == dest) return A[now];

    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        string tmp = dfs(nxt, now, dest);
        if(tmp != "") return A[now] + tmp;
    }

    return "";
}

ll result(string str) {
    ll digit = 1;
    ll ret = 0;
    for(int i = str.size() - 1; i >= 0; i--) {
        ret += digit * (str[i] - '0');
        ret %= MOD;
        digit = (digit * 10) % MOD;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N >> Q;

    for(int i = 1; i <= N; i++) cin >> A[i];

    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    while(Q--) {
        int x, y; cin >> x >> y;
        string ret = dfs(x, 0, y);
        cout << result(ret) << '\n';
    }
}