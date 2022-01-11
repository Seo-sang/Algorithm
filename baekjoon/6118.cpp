#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MN = 20001;
bool visit[MN];

vector<int> g[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ans;
    int dist = 0;
    visit[1] = true;
    queue<pair<int,int>> q;
    q.push({1, 0});
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int e : g[now.first]) {
            if(visit[e]) continue;
            visit[e] = true;
            if(dist < now.second + 1) {
                dist = now.second + 1;
                ans.clear();
                ans.push_back(e);
            }
            else if(dist == now.second + 1) {
                ans.push_back(e);
            }
            q.push({e, now.second + 1});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.front() << ' ' << dist << ' ' << ans.size();
}