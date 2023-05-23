#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
map<string, set<string> > child;
map<string, set<string> > ans;
map<string, int> cnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N;
    for(int i = 0; i < N; i++) {
        string a; cin >> a;
        cnt[a] = 0;
        ans[a] = set<string>();
    }

    cin >> M;
    while(M--) {
        string a, b; cin >> a >> b;
        cnt[a]++;
        child[b].insert(a);
    }
    queue<string> q;
    set<string> root;

    for(auto it : cnt) {
        if(it.second == 0) {
            q.push(it.first);
            root.insert(it.first);
        }
    }

    cout << root.size() << '\n';
    for(string e : root)
        cout << e << ' ';
    cout << '\n';
    
    while(!q.empty()) {
        string now = q.front(); q.pop();

        for(string nxt : child[now]) {
            cnt[nxt]--;
            if(cnt[nxt] == 0) {
                ans[now].insert(nxt);
                q.push(nxt);
            }
        }
    }
    
    for(auto it : ans) {
        cout << it.first << ' ' << it.second.size();
        for(auto it2 : it.second) {
            cout << ' ' << it2;
        }
        cout << '\n';
    }
}