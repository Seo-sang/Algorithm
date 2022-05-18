#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
bool truth[MN];
bool vst[MN];
vector<int> g[MN];
vector<vector<int> > party;

int main() {
    int N, M, T; cin >> N >> M >> T;
    while(T--) {
        int a; cin >> a;
        truth[a] = true;
    }
    while(M--) {
        int num; cin >> num;
        vector<int> tmp;
        for(int i = 0; i < num; i++) {
            int a; cin >> a;
            tmp.push_back(a);
            for(int j = 0; j < i; j++) {
                g[a].push_back(tmp[j]);
                g[tmp[j]].push_back(a);
            }
        }
        party.push_back(tmp);
    }

    for(int i = 1; i <= N; i++) {
        if(truth[i]) {
            if(vst[i]) continue;
            queue<int> q; q.push(i);
            vst[i] = true;
            while(!q.empty()) {
                int now = q.front(); q.pop();
                for(int nxt : g[now]) {
                    if(vst[nxt]) continue;
                    vst[nxt] = true;
                    truth[nxt] = true;
                    q.push(nxt);
                }
            }
        }
    }

    int ans = 0;
    for(vector<int> p : party) 
        if(!truth[p[0]]) ans++;
    cout << ans;
}