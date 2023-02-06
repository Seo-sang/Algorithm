#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 1001;
vector<int> g[MN];
int child[MN];
int ans[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        child[b]++;
    }
    queue<P> q;
    for(int i = 1; i <= N; i++) {
        if(child[i] == 0) {
            ans[i] = 1;
            q.push(make_pair(i, 1));
        }
    }

    while(!q.empty()) {
        P now = q.front(); q.pop();
        for(int nxt : g[now.first]) {
            child[nxt]--;
            if(child[nxt] == 0) {
                ans[nxt] = now.second + 1;
                q.push(make_pair(nxt, now.second + 1));
            }
        }
    }

    for(int i = 1; i <= N; i++)
        cout << ans[i] << ' ';

}