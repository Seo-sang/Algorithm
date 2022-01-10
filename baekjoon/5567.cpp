#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MN = 501;
vector<int> g[MN];
bool visit[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    visit[1] = true;
    queue<int> q;
    for(int e : g[1]) {
        visit[e] = true;
        ans++;
        q.push(e);
    }

    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int e : g[now]) {
            if(visit[e]) continue;
            visit[e] = true;
            ans++;
        }
    }

    cout << ans;
}