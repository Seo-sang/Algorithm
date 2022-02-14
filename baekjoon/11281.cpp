#include <bits/stdc++.h>

using namespace std;
const int MN = 20002;
vector<int> g[MN], rg[MN], st;
vector<vector<int> > scc;
bool vst[MN], ans[MN];
int N ,M;

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

int Not(int a) {
    if(a > N) return a - N;
    else return a + N;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        if(a < 0) a = -a + N;
        if(b < 0) b = -b + N;
        g[Not(a)].push_back(b);
        g[Not(b)].push_back(a);
        rg[a].push_back(Not(b));
        rg[b].push_back(Not(a));
    }

    for(int i = 1; i <= N * 2; i++) {
        if(vst[i]) continue;
        vst[i] = true;
        dfs(i);
    }

    reverse(st.begin(), st.end());
    memset(vst, 0, sizeof(vst));

    for(int n : st) {
        if(vst[n]) continue;
        vst[n] = true;
        scc.push_back(vector<int> ());
        dfs2(n);
    }

    memset(vst, 0, sizeof(vst));

    for(vector<int> &i : scc) {
        for(int j : i) {
            if(vst[Not(j)]) {
                cout << 0;
                return 0;
            }
            vst[j] = true;
        }
        memset(vst,0, sizeof(vst));
    }

    cout << "1\n";

    for(vector<int> &i : scc) {
        for(int j : i) {
            if(!vst[j]) {
                vst[j] = true;
                vst[Not(j)] = true;
                ans[j] = 0;
                ans[Not(j)] = 1;
            }
        }
    }

    for(int i = 1; i <= N; i++)
        cout << ans[i] << ' ';

    return 0;
}