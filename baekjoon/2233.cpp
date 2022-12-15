#include <bits/stdc++.h>

using namespace std;
string str;
const int MN = 2001;
vector<int> g[MN];
int h[MN];
int dp[20][MN];
pair<int,int> pos[MN];
int num[MN * 2];

void dfs(int n, int prev) {
    for(int nxt : g[n]) {
        if(prev == nxt) continue;
        h[nxt] = h[n] + 1;
        dp[0][nxt] = n;
        dfs(nxt, n);
    }
}

int LCA(int a, int b) {
    if(h[a] < h[b]) swap(a, b);

    int gap = h[a] - h[b];

    for(int i = 0; i < 20; i++)
        if(gap & (1 << i))
            a = dp[i][a];

    if(a == b) return a;

    for(int i = 19; i >= 0; i--)
        if(dp[i][a] != dp[i][b])
            a = dp[i][a], b = dp[i][b];

    return dp[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    cin >> str;
    int X, Y; cin >> X >> Y;
    
    vector<int> st;
    st.push_back(0);
    int now = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') {
            now++;
            g[st.back()].push_back(now);
            g[now].push_back(st.back());
            st.push_back(now);
            pos[now].first = i + 1;
            num[i + 1] = now;
        }
        else {
            pos[st.back()].second = i + 1;
            num[i + 1] = st.back();
            st.pop_back();
        }
    }

    dfs(0, 0);

    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= N; j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];

    int cut = LCA(num[X], num[Y]);
    cout << pos[cut].first << ' ' << pos[cut].second;

}