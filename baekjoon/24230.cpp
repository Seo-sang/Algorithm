#include <bits/stdc++.h>

using namespace std;

const int MN = 200001;
vector<int> g[MN];
int color[MN];

int dfs(int now ,int prev, int nowcolor) {
    int ret;

    if(nowcolor == color[now]) ret = 0;
    else ret =1 ;
 
    for(int nxt : g[now]) {
        if(nxt == prev) continue;
        ret += dfs(nxt, now, color[now]);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> color[i];
    for(int i = 0; i < N - 1; i ++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    cout << dfs(1, 0, 0);
}