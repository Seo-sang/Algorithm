#include <bits/stdc++.h>

using namespace std;

const int MN = 501;
set<int> g[MN];
int arr[MN];
int entry[MN];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(arr, 0, sizeof(arr));
        memset(entry, 0, sizeof(entry));
        ans.clear();
        for(int i = 0; i < MN; i++) g[i].clear();

        int N; cin >> N;
        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
            for(int j = 1; j < i; j++) {
                entry[arr[j]]++;
                g[arr[i]].insert(arr[j]);
            }
        }
        int M; cin >> M;
        while(M--) {
            int a, b; cin >> a >> b;
            if(g[a].find(b) == g[a].end()) {
                entry[b]++;
                entry[a]--;
                g[b].erase(a);
                g[a].insert(b);
            }
            else {
                entry[a]++;
                entry[b]--;
                g[a].erase(b);
                g[b].insert(a);
            }
        }
        queue<int> q;
        for(int i = 1; i <= N; i++) {
            if(entry[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(auto it = g[now].begin(); it != g[now].end(); it++) {
                int nxt = *it;
                entry[nxt]--;
                if(entry[nxt] == 0) {
                    q.push(nxt);
                    ans.push_back(nxt);
                }
            }
        }

        if(ans.size() == N) {
            for(auto it = ans.rbegin(); it != ans.rend(); it++)
                cout << *it << ' ';
            cout << '\n';
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }
}