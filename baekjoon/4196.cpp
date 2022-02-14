#include <bits/stdc++.h>

using namespace std;
const int MN = 100001;
vector<int> g[MN], st;
bool visited[MN];

void dfs(int n) {
    //cout << n << endl;
    for(int nxt : g[n]) {
        if(visited[nxt]) continue;
        visited[nxt] = true;
        dfs(nxt);
    }

    st.push_back(n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(visited, 0, sizeof(visited));
        st.clear();
        for(int i = 0; i < MN; i++) {
            g[i].clear();
        }

        int N, M; cin >> N >> M;
        while(M--) {
            int x, y; cin >> x >> y;
            g[x].push_back(y);
        }

        for(int i = 1; i <= N; i++) {
            if(visited[i]) continue;
            visited[i] = true;
            dfs(i);
        }

        reverse(st.begin(), st.end());
        memset(visited, 0, sizeof(visited));

        int ans = 0;
        for(int i = 0; i < st.size(); i++) {
            int e = st[i];
            if(visited[e]) continue;
            visited[e] = true;
            dfs(e);
            ans++;
        }
        cout << ans << '\n';
    }
}