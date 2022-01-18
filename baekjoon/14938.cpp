#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>

using namespace std;
const int MN = 101;
const int INF = 1e9;

vector<P> g[MN];

int item[MN];
int floyd[MN][MN];
int main() {
    int N, M, R; cin >> N >> M >> R;
    fill(&floyd[0][0], &floyd[N][N + 1], INF);

    for(int i = 1; i <= N; i++) {
        cin >> item[i];
        floyd[i][i] = 0;
    }

    while(R--) {
        int a, b, c; cin >> a >> b >> c;
        floyd[a][b] = c;
        floyd[b][a] = c;
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(floyd[i][j] <= M)
                cnt += item[j];
        }
        ans = max(ans, cnt);
    }

    cout << ans;
    

}