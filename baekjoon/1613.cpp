#include <bits/stdc++.h>

using namespace std;
const int MN = 401;
const int INF = 1e9;
int floyd[MN][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    fill(&floyd[0][0], &floyd[N][N + 1], INF);

    while(K--) {
        int a, b; cin >> a >> b;
        floyd[a][b] = 1;
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    int S; cin >> S;
    while(S--) {
        int a, b; cin >> a >> b;
        if(floyd[a][b] != INF) cout << -1 << '\n';
        else if(floyd[b][a] != INF) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}