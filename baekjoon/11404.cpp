#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MN = 101;
const int INF = 1e9;

int floyd[MN][MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    fill(&floyd[0][0], &floyd[N][N + 1], INF);

    for(int i = 1; i <= N; i++)
        floyd[i][i] = 0;

    while(M--) {
        int a, b, c; cin >> a >> b >> c;
        floyd[a][b] = min(floyd[a][b], c);
    }
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int k = 1; k <= N; k++)
                floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k]);


    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(floyd[i][j] == INF) cout << "0 ";
            else cout << floyd[i][j] << ' ';
        }
        cout << '\n';
    }
}