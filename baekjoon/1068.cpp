#include <bits/stdc++.h>

using namespace std;
const int MN = 51;

int p[MN];
vector<int> tree[MN];
int leaf, E;

void dfs(int n) {
    int cnt = 0;
    for(int e : tree[n]) {
        if(e != E) {
            cnt++;
            dfs(e);
        }
    }
    if(cnt == 0) leaf++;
}

int main() {
    int N; cin >> N;
    int root;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        tree[p[i]].push_back(i);
        if(p[i] == -1) root = i;
    }
    cin >> E;
    if(E != root)
        dfs(root);

    cout << leaf;
}