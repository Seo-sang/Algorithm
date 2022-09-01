#include <bits/stdc++.h>

using namespace std;
const int MN = 501;
vector<int> g[MN];
bool vst[MN];
int cnt[MN];

int main() {
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); // a < b
    }

    for(int i = 1; i <= N; i++) {
        queue<int> q; q.push(i);
        memset(vst, 0, sizeof(vst));
        vst[i] = true;
        cnt[i]++;
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(int nxt : g[now]) {
                if(vst[nxt]) continue;
                vst[nxt] = true;
                cnt[i]++;
                cnt[nxt]++;
                q.push(nxt);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(cnt[i] == N) ans++;

    cout << ans;
}