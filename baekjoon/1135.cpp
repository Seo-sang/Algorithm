#include <bits/stdc++.h>

using namespace std;
const int MN = 51;
vector<int> g[MN];
int dp[MN];

int dfs(int n) {
    if(g[n].size() == 0) return 0;
    vector<int> tmp;
    for(int nxt : g[n])
        tmp.push_back(dfs(nxt));
    
    sort(tmp.begin(), tmp.end(), greater<int>());
    int ret = 0;
    for(int i = 0; i < tmp.size(); i++)
        ret = max(ret, tmp[i] + i + 1);

    return ret;
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        if(i > 0)
            g[a].push_back(i);
    }
    cout << dfs(0);

}