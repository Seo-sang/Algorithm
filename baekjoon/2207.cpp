#include <bits/stdc++.h>

using namespace std;
const int MN = 20002;
vector<int> g[MN], rg[MN], st;
vector<vector<int> > scc;
bool vst[MN];

int N, M;

int Not(int a) {
    if(a > M) return a - M;
    else return a + M;
}

void dfs(int n) {
    for(int nxt : g[n]) {
        if(vst[nxt]) continue;
        vst[nxt] = true;
        dfs(nxt);
    }

    st.push_back(n);
}

void dfs2(int n) {
    for(int nxt : rg[n]) {
        if(vst[nxt]) continue;
        vst[nxt] = true;
        dfs2(nxt);
    }

    scc.back().push_back(n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        if(a < 0) a = -a + M;
        if(b < 0) b = -b + M;
        g[Not(a)].push_back(b);
        g[Not(b)].push_back(a);
        rg[a].push_back(Not(b));
        rg[b].push_back(Not(a));
    }

    for(int i = 1; i <= M * 2; i++) {
        if(vst[i]) continue;
        vst[i] = true;
        dfs(i);
    }

    reverse(st.begin(), st.end());
    memset(vst, 0, sizeof(vst));

    for(int n : st) {
        if(vst[n]) continue;
        vst[n] = true;
        scc.push_back(vector<int>());
        dfs2(n);
    }

    memset(vst, 0, sizeof(vst));

    for(vector<int> &i : scc) {
        for(int j : i) {
            if(vst[Not(j)]) {
                cout << "OTL";
                return 0;
            }
            vst[j] = true;
        }
        memset(vst, 0, sizeof(vst));
    }

    cout << "^_^";
}