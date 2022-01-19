#include <bits/stdc++.h>

using namespace std;

const int MN = 10001;
int arr[MN];
vector<int> g[MN];
vector<int> ans;

//0은 포함x, 1은 포함o
int dp[MN][2];
vector<pair<int,int> > child[MN][2];

int dfs(int n, int prev, int in) {
    int &ret = dp[n][in];
    if(ret != -1) return ret;
    (in == 0) ? (ret = 0) : (ret = arr[n]);
    int tmp;
    for(int e : g[n]) {
        if(e == prev) continue;
        if(in == 0) {
            int a = dfs(e, n, 0);
            int b = dfs(e, n, 1);
            if(a > b) {
                ret += a;
                child[n][in].push_back(make_pair(e, 0));
            }
            else {
                ret += b;
                child[n][in].push_back(make_pair(e, 1));
            }
        }
        else {
            ret += dfs(e, n, 0);
            child[n][in].push_back(make_pair(e, 0));
        }
    }
    return ret;
}

void path(int n, int in) {
    if(in == 1)
        ans.push_back(n);
    if(n == 0) return;
    for(pair<int,int> e : child[n][in]) {
        path(e.first, e.second);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    memset(dp, -1, sizeof(dp));

    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int a = dfs(1, 0, 0);
    int b = dfs(1, 0, 1);
    if(a > b) {
        cout << a << '\n';
        path(1, 0);
    }
    else {
        cout << b << '\n';
        path(1, 1);
    }
    sort(ans.begin(), ans.end());
    for(int e : ans)
        cout << e << ' ';

}