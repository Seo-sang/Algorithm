#include <bits/stdc++.h>

using namespace std;

const int MN = 200001;
vector<int> g[MN];
int connect[MN];
int id[MN];
int N, Q; 

void findCycle() {

    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(connect[i] == 1) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int now = q.front(); q.pop();
        connect[now]--;
        for(int nxt : g[now]) {
            if(connect[nxt] == 0) continue;
            connect[nxt]--;
            if(connect[nxt] == 1) {
                q.push(nxt);
            }
        }
    }

}

void dfs(int now, int prev, int value) {
    id[now] = value;
    for(int nxt : g[now]) {
        if(connect[nxt] > 0 || nxt == prev) continue;
        dfs(nxt, now, value);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        connect[a]++, connect[b]++;
    }

    findCycle();


    int value = 1;
    for(int i = 1; i <= N; i++) {
        if(connect[i] == 0) continue;
        dfs(i, 0, value);
        value++;
    }


    while(Q--) {
        int u, v; cin >> u >> v;
        if(id[u] == id[v]) cout<< "1\n";
        else cout << "2\n";
    }

}