#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MN = 101;
bool visit[MN];
vector<int> g[MN];

int main() {
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    queue<int> q;
    q.push(1);
    visit[1] = true;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int e : g[now]) {
            if(visit[e]) continue;
            visit[e] = true;
            ans++;
            q.push(e);
        }
    }
    cout << ans;
}