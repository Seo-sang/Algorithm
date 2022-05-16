#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 401;
const int INF = 1e9;

int floyd[MN][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int V, E; cin >> V >> E;
    fill(&floyd[0][0], &floyd[MN-1][MN], INF);
    for(int i = 0; i < E; i++) {
        int a, b, c; cin >> a >> b >> c;
        floyd[a][b] = c;
    }

    for(int k = 1; k <= V; k++)
        for(int i = 1; i <= V; i++)
            for(int j = 1; j <= V; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    int ans = INF;
    for(int i = 1; i <= V; i++)
        ans = min(ans, floyd[i][i]);
    if(ans == INF) cout << -1;
    else cout << ans;
}