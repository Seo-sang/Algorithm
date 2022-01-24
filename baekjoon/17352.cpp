#include <bits/stdc++.h>

using namespace std;

const int MN = 300001;
vector<int> g[MN];
bool visited[MN];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N - 2; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    visited[1] = true;
    q.push(1);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int e : g[now]) {
            if(visited[e]) continue;
            visited[e] = true;
            q.push(e);
        }
    }
    int ans = 1;
    for(; ans <= N; ans++) {
        if(!visited[ans]) break;
    }

    cout << 1 << ' ' << ans;
}