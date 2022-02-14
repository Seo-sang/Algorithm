#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
vector<int> g[MN];
vector<int> st;
int arr[MN];
int fin[MN];
bool visited[MN];

void dfs(int n) {
    visited[n] = true;
    for(int nxt : g[n]) {
        if(visited[nxt]) continue;
        dfs(nxt);
    }

    st.push_back(n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N, K; cin >> N >> K;
        for(int i =1; i <= N; i++)
            cin >> arr[i];

        while(K--) {
            int a, b; cin >> a >> b;
            g[a].push_back(b);
        }

        for(int i = 1; i <= N; i++)
            if(!visited[i])
                dfs(i);

        reverse(st.begin(), st.end());

        int W; cin >> W;
        for(int e : st) {
            fin[e] += arr[e];
            for(int nxt : g[e])
                fin[nxt] = max(fin[nxt], fin[e]);
        }

        cout << fin[W] << '\n';
        memset(arr, 0, sizeof(arr));
        memset(fin, 0, sizeof(fin));
        memset(visited, 0, sizeof(visited));
        st.clear();
        for(int i = 0; i <= N; i++)
            g[i].clear();
    }
}