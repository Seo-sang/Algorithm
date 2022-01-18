#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>
using namespace std;

const int MN = 801;
const int INF = 8000000;
int floyd[MN][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, E; cin >> N >> E;
    fill(&floyd[0][0], &floyd[N][N+1], INF);
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        floyd[a][b] = c;
        floyd[b][a] = c;
    }

    int v1, v2; cin >> v1 >> v2;

    for(int i = 1; i <= N; i++)
        floyd[i][i] = 0;

    for(int k = 1; k <= N; k++) 
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    int ans = min(floyd[1][v1] + floyd[v1][v2] + floyd[v2][N], floyd[1][v2] + floyd[v2][v1] + floyd[v1][N]);
    if(ans >= INF) cout << -1;
    else cout << ans;
}