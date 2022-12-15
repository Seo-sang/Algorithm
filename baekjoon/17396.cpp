#include <bits/stdc++.h>
#define ll long long
#define P pair<long long,int>
using namespace std;

const int MN = 100001;
const long long INF = 1e15;
vector<P> g[MN];
bool visible[MN];
ll dp[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    fill(&dp[0], &dp[N], INF);

    for(int i = 0; i < N; i++) {
        cin >> visible[i];
    }

    while(M--) {
        int a, b, t; cin >> a >> b >> t;
        g[a].push_back(make_pair(t, b));
        g[b].push_back(make_pair(t, a));
    }

    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(make_pair(0, 0));
    dp[0] = 0;

    while(!pq.empty()) {
        P now = pq.top(); pq.pop();
        if(dp[now.second] < now.first) continue;
        for(P nxt : g[now.second]) {
            if(nxt.second != N - 1 && visible[nxt.second]) continue;
            if(dp[nxt.second] > now.first + nxt.first) {
                dp[nxt.second] = now.first + nxt.first;
                pq.push(make_pair(dp[nxt.second], nxt.second));
            }
        }
    }
    cout << (dp[N - 1] == INF ? -1 : dp[N - 1]);
    return 0;
}