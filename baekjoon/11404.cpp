#include <bits/stdc++.h>

using namespace std;
#define P pair<int,int>
const int MN = 101;
const int INF = 1e9;
int floyd[MN][MN];

int main() {
    fill(&floyd[0][0], &floyd[MN - 1][MN], INF);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        floyd[a][b] = min(floyd[a][b], c);
    }
    for(int i = 1; i <= N; i++)
        floyd[i][i] = 0;
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            cout << ((floyd[i][j] == INF) ? 0 : floyd[i][j]) << ' ';
        cout << '\n';
    }
}