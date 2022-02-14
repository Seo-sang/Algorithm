#include <bits/stdc++.h>

using namespace std;
const int MN = 10001;
vector<int> g[MN];
vector<int> rg[MN];
vector<int> st;
vector<vector<int> > SCC;
bool visited[MN];

void dfs(int n) {
    for(int nxt : g[n]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        dfs(nxt);
    }
    st.push_back(n);
}

void dfs2(int n) {
    for(int nxt : rg[n]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        dfs2(nxt);
    }

    SCC.back().push_back(n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int V, E; cin >> V >> E;
    while(E--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    for(int i = 1; i <= V; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i);
    }

    reverse(st.begin(), st.end());
    memset(visited, 0, sizeof(visited));

    for(int n : st) {
        if(visited[n]) continue;
        visited[n] = true;
        SCC.push_back(vector<int> ());
        dfs2(n);
    }
    for(vector<int> &e : SCC)
        sort(e.begin(), e.end());

    sort(SCC.begin(), SCC.end());

    cout << SCC.size() << '\n';
    for(vector<int> &e : SCC) {
        for(int n : e) {
            cout << n << ' ';
        }
        cout << "-1\n";
    }

}