#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 101;
const int INF = 1e9;
vector<P> g[MN];
vector<int> pos;
int dist[MN][MN];

int main() {
    int T; cin >> T;
    while(T--) {
        int N, M, K; cin >> N >> M;
        fill(&dist[0][0], &dist[N][N + 1], INF);
        pos.clear();
        for(int i = 1; i <= N; i++) {
            dist[i][i] = 0;
            g[i].clear();
        }
        while(M--) {
            int a, b, c; cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }
        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        cin >> K;
        while(K--) {
            int a; cin >> a;
            pos.push_back(a);
        }
        int ans = INF;
        int room;
        for(int i = 1; i <= N; i++) {
            int tmp = 0;
            for(int d : pos)
                tmp += dist[i][d];
            if(ans > tmp) {
                room = i;
                ans = tmp;
            }
        }
        cout << room << '\n';
    }
}