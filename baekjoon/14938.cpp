#include <bits/stdc++.h>

using namespace std;
const int MN = 101;
const int INF = 1e9;
int item[MN];
int floyd[MN][MN];

int main() {
    int N, M, R; cin >> N >> M >> R;
    fill(&floyd[0][0], &floyd[MN-1][MN], INF);
    for(int i  = 1; i <= N; i++) {
        cin >> item[i];
        floyd[i][i] = 0;
    }
    
    while(R--) {
        int a, b, l; cin >> a >> b >> l;
        floyd[a][b] = l;
        floyd[b][a] = l;
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int tmp = 0;
        for(int j = 1; j <= N; j++) {
            if(floyd[i][j] <= M)
                tmp += item[j];
        }

        ans = max(ans, tmp);
    }

    cout << ans;
}