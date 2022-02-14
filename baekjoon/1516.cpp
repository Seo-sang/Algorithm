#include <bits/stdc++.h>

using namespace std;
const int MN = 501;
vector<int> g[MN], st;
int arr[MN];
int ans[MN];
bool visited[MN];

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
    int N; cin >> N;
    for(int i = 1;i <= N; i++) {
        cin >> arr[i];
        while(1) {
            int a; cin >> a;
            if(a == -1) break;
            g[a].push_back(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i);
    }
    reverse(st.begin(), st.end());

    for(int n : st) {
        ans[n] += arr[n];
        for(int nxt : g[n])
            ans[nxt] = max(ans[nxt], ans[n]);
    }

    for(int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}