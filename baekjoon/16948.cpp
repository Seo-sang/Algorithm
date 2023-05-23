#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 201;
const int INF = 1e9;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int dist[MN][MN];

int main() {
    int N; cin >> N;
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

    fill(&dist[0][0], &dist[N][N+1], INF);
    dist[r1][c1] = 0;
    queue<pii> q; q.push(pii(r1, c1));

    while(!q.empty()) {
        pii now = q.front(); q.pop();
        int ndist = dist[now.first][now.second] + 1;
        for(int d = 0; d < 6; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(dist[nx][ny] > ndist) {
                    dist[nx][ny] = ndist;
                    q.push(pii(nx, ny));
                }
                if(nx == r2 && ny == c2) break;
            }
        }
    }

    if(dist[r2][c2] == INF) cout << -1;
    else cout << dist[r2][c2];
}