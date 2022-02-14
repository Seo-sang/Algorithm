#include <bits/stdc++.h>

using namespace std;
const int MN = 42;
vector<int> g[MN * 2], rg[MN * 2], st;
vector<vector<int> > scc;
bool visited[MN];

int N, M;

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

    scc.back().push_back(n);
}

int Not(int n) {
    if(n > N) return n -= N;
    else return n += N;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        if(a < 0) a = -a + N;
        if(b < 0) b = -b + N;
        g[Not(a)].push_back(b);
        g[Not(b)].push_back(a);
        rg[a].push_back(Not(b));
        rg[b].push_back(Not(a));
    }

    for(int i = 1; i <= N * 2; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i);
    }

    reverse(st.begin(), st.end());
    memset(visited, 0, sizeof(visited));

    for(int n : st) {
        if(visited[n]) continue;
        visited[n] = true;
        scc.push_back(vector<int>());
        dfs2(n);
    }

    memset(visited, 0, sizeof(visited));

    for(vector<int> &e : scc) {
        for(int n : e) {
            if(visited[Not(n)]) {
                cout << 0;
                return 0;
            }
            visited[n] = true;
        }
        for(int n : e)
            visited[n] = false;
    }

    cout << 1;
}