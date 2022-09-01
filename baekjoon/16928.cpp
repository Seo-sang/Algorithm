#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 101;
const int INF = 1e9;
int N, M; 
int ladder[MN];
int sname[MN];
int dp[MN];

int main() {
    cin >> N >> M;
    fill(dp, dp + MN, INF);
    for(int i = 0; i < N; i++) {
        int x, y, cin >> x >> y;
        ladder[x] = y;
    }
    for(int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        sname[u] = v;
    }

    

}