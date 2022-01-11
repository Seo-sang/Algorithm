#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MN = 101;
vector<int> g[MN];
bool visit[MN];

int main() {
    int N; cin >> N;
    int S, E; cin >> S >> E;
    int M; cin >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<pair<int,int>> q;
    q.push({S, 0});
    visit[S] = true;
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int e : g[now.first]) {
            if(visit[e]) continue;
            if(e ==  E) {
                cout << now.second + 1;
                return 0;
            }
            visit[e] = true;
            q.push({e, now.second + 1});
        }
    }

    cout << -1;
}