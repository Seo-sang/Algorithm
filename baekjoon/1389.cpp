#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 101;
const int INF = 1e9;
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
    int mnum = INF;
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        memset(visit, 0, sizeof(visit));
        visit[i] = true;
        queue<pair<int,int>> q;
        q.push({i, 0});
        while(!q.empty()) {
            pair<int,int> now = q.front(); q.pop();
            for(int e : g[now.first]) {
                if(visit[e]) continue;
                visit[e] = true;
                cnt += now.second + 1;
                q.push({e, now.second + 1});
            }
        }
        if(mnum > cnt) {
            mnum = cnt;
            ans = i;
        }
    }

    cout << ans;
}