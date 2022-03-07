#include <bits/stdc++.h>

using namespace std;
map<int,vector<int>> g;
map<int, bool> root, vst;
bool ans;

void dfs(int n) {
    for(int nxt : g[n]) {
        if(vst[nxt]) {
            ans = false;
            return;
        }
        vst[nxt] = true;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int u, v, k = 1;
    while(true) {
        cin >> u >> v;
        if(u == -1 && v == -1) break;
        if(u == 0 && v == 0) {
            int start;
            for(auto it = root.begin(); it != root.end(); it++)
                if(it->second == false)
                    start = it->first;
            ans = true;
            vst[start] = true;
            dfs(start);
            for(auto &it : vst)
                if(it.second == false)
                    ans = false;

            if(ans) cout << "Case " << k << " is a tree.\n";
            else cout << "Case " << k << " is not a tree.\n";
            g.clear();
            root.clear();
            vst.clear();
            k++;
        }
        else {
            vst[u] = vst[v] = false;
            g[u].push_back(v);
            if(root.find(u) == root.end())
                root[u] = false;
            root[v] = true;
        }
    }
}