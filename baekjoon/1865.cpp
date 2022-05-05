#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int MN = 501;
const int INF = 1e9;
vector<P> g[MN];
int dist[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N, M, W; cin >> N >> M >> W;

        for(int i = 0; i <= N; i++) g[i].clear();
        fill(&dist[0], &dist[N + 1], INF);
        for(int i = 0; i < M; i++) {
            int S, E, T; cin >> S >> E >> T;
            g[S].push_back(make_pair(T, E));
            g[E].push_back(make_pair(T, S));
        }
        for(int i = 0; i < W; i++) {
            int S, E, T; cin >> S >> E >> T;
            g[S].push_back(make_pair(-T, E));
        }
        dist[1] = 0;
        bool ans = false;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                for(P nxt : g[j]) {
                    if(i < N)
                        dist[nxt.second] = min(dist[nxt.second], dist[j] + nxt.first);
                    else
                        if(dist[nxt.second] > dist[j] + nxt.first)
                            ans = true;
                }
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}