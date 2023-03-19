#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 5001;
const int INF = 1e9;

vector<pii> g[MN];
int d[MN];

int main() {
    int V, E, P; cin >> V >> E >> P;
    fill(d, d + MN, INF);
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
        g[b].push_back(make_pair(c, a));
    }

    d[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, 1));
    while(!pq.empty()) {
        pii now = pq.top(); pq.pop();

        for(pii nxt : g[now.second]) {
            if(d[nxt.second] > d[now.second] + nxt.first) {
                d[nxt.second] = d[now.second] + nxt.first;
                pq.push(make_pair(d[nxt.second], nxt.second));
            }
        }
    }
    int distP = d[P];
    int distV = d[V];

    fill(d, d + MN, INF);
    d[P] = 0;
    pq.push(make_pair(0, P));
    while(!pq.empty()) {
        pii now = pq.top(); pq.pop();
        for(pii nxt : g[now.second]) {
            if(d[nxt.second] > d[now.second] + nxt.first) {
                d[nxt.second] = d[now.second] + nxt.first;
                pq.push(make_pair(d[nxt.second], nxt.second));
            }
        }
    }

    if(distP + d[V] == distV) cout << "SAVE HIM";
    else cout << "GOOD BYE";
}