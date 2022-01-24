#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;

vector<int> g[MN];
bool visited[MN];

int main() {
    int a, b; cin >> a >> b;
    int N, M; cin >> N >> M;
    while(M--) {
        int x, y; cin >>x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(a == b) {
        cout << 0;
        return 0;
    }
    queue<pair<int,int> >q;
    q.push(make_pair(a, 0));
    visited[a] = true;
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int e : g[now.first]) {
            if(visited[e]) continue;
            visited[e] = true;
            if(e == b) {
                cout << now.second + 1;
                return 0;
            }
            q.push(make_pair(e, now.second + 1));
        }
    }

    cout << -1;
}