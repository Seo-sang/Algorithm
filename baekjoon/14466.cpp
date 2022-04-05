#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 101;
set<pair<P,P> > s;
bool cow[MN][MN];
bool vst[MN][MN];
int p[MN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N,K, R; cin >> N >> K >> R;

    for(int i = 0; i < R; i++) {
        P a, b; cin >> a.first >> a.second >> b.first >> b.second;
        s.insert(make_pair(a, b));
        s.insert(make_pair(b, a));
    }
    for(int i = 0; i < K; i++) {
        int a, b; cin >> a >> b;
        cow[a][b] = true;
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(!cow[i][j]) continue;
            memset(vst, 0, sizeof(vst));
            vst[i][j] = true;
            queue<P> q; q.push(make_pair(i, j));
            while(!q.empty()) {
                P now = q.front(); q.pop();
                for(int d = 0; d < 4; d++) {
                    int nx = now.first + dx[d];
                    int ny = now.second + dy[d];
                    if(nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                        if(vst[nx][ny]) continue;
                        P nxt = make_pair(nx, ny);
                        if(s.find(make_pair(now, nxt)) != s.end()) continue;
                        vst[nx][ny] = true;
                        q.push(nxt);
                        if(cow[nx][ny])
                            cnt++;
                    }
                }
            }
        }
    }
    cnt /= 2;
    int ans = K * (K - 1) / 2;
    cout << ans - cnt;
}