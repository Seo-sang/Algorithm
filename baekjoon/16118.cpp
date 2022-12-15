#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 4001;
const int INF = 2e9;
vector<P> g1[MN];
vector<P> g2[MN][2];
int dist1[MN];
int dist2[MN][2];

struct node {
    int d, start, turn;
    node(int d, int start, int turn) : d(d), start(start), turn(turn) {}
};

struct cmp {
    bool operator()(node a, node b) {
        return a.d > b.d;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b, d; cin >> a >> b >> d;
        g1[a].push_back(make_pair(d * 2, b));
        g1[b].push_back(make_pair(d * 2, a));
        g2[a][0].push_back(make_pair(d, b));
        g2[a][1].push_back(make_pair(d * 4, b));
        g2[b][0].push_back(make_pair(d, a));
        g2[b][1].push_back(make_pair(d * 4, a));
    }
    priority_queue<P, vector<P>, greater<P> >pq1;
    fill(&dist1[0], &dist1[N + 1], INF);
    dist1[1] = 0;
    pq1.push(make_pair(0, 1));
    while(!pq1.empty()) {
        P now = pq1.top(); pq1.pop();
        if(dist1[now.second] < now.first) continue;
        for(P nxt : g1[now.second]) {
            if(dist1[nxt.second] > now.first + nxt.first) {
                dist1[nxt.second] = now.first + nxt.first;
                pq1.push(make_pair(dist1[nxt.second], nxt.second));
            }
        }
    }

    priority_queue<node, vector<node>, cmp> pq2;
    fill(&dist2[0][0], &dist2[N][2], INF);
    dist2[1][1] = 0;
    pq2.push(node(0, 1, 1));
    while(!pq2.empty()) {
        node now = pq2.top(); pq2.pop();
        if(dist2[now.start][now.turn] < now.d) continue;
        int nturn = (now.turn + 1) % 2;
        for(P nxt : g2[now.start][nturn]) {
            if(dist2[nxt.second][nturn] > now.d + nxt.first) {
                dist2[nxt.second][nturn] = now.d + nxt.first;
                pq2.push(node(dist2[nxt.second][nturn], nxt.second, nturn));
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(dist1[i] < dist2[i][0] && dist1[i] < dist2[i][1]) ans++;
    }
    cout << ans;
}