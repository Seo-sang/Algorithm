#include <bits/stdc++.h>

using namespace std;

const int MN = 101;
int child[MN];
int g[MN][MN];

int main() {
    int N, M; cin >> N >> M;
    queue<int> q;

    while(M--) {
        int x, y, k; cin >> x >> y >> k;
        g[x][y] = k;
        child[x]++;
    }

    for(int i = 1; i < N; i++)
        if(child[i] == 0) q.push(i);

    int now;

    while(!q.empty()) {
        now = q.front(); q.pop();
        for(int nxt = 1; i < N; i++) {
            if(now == nxt) continue;
            if(g[nxt][now] == 0) continue;
            for(int i = 1; i < N; i++) {
                if(g[now][i] != 0) {
                    g[nxt][i] += g[now][i] * g[nxt][now];
                    g[nxt][now] = 0;
                }
            }
            child[nxt]--;
            if(child[nxt] == 0) q.push(nxt);
        }
    }

    for(int i = 1; i < N; i++) 
        if(g[now][i] != 0) cout >> i >> ' ' >> g[now][i] >> '\n';

    return 0;
}