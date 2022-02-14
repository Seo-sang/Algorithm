#include <bits/stdc++.h>

using namespace std;
const int MN = 32001;
vector<int> g[MN], st;
bool  visited[MN];

void dfs(int n) {
    for(int nxt : g[n]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        dfs(nxt);
    }

    st.push_back(n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i);
    }

    reverse(st.begin(), st.end());

    for(int e : st)
        cout << e << ' ';
}