#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 328001;

vector<int> g[MN];
bool vst[MN];

int main() {
    int N, S, P; cin >> N >> S >> P;
    for(int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int cnt = 0;

    queue<pii> q;
    q.push(make_pair(P, 0));
    int ans = 1;
    vst[P] = true;
    while(!q.empty() && cnt != 2) {
        pii now = q.front(); q.pop();
        for(int nxt : g[now.first]) {
            if(vst[nxt]) continue;
            vst[nxt] = true;
            if(1 <= nxt && nxt <= S) {
                cnt++;
                ans += now.second + 1;
                if(cnt == 2) break;
            }
            q.push(make_pair(nxt, now.second + 1));
        }
    }
    cout << N - ans;
}