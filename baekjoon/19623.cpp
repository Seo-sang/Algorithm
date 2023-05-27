#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 100001;

vector<int> v;  //압축 좌표
map<int, vector<pii> > m;
int dp[MN * 2];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        m[a].push_back(pii(b, c));
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
        if(i > 0)
            dp[i] = max(dp[i], dp[i-1]);
        for(pii e : m[v[i]]) {
            int end = lower_bound(v.begin(), v.end(), e.first) - v.begin();
            dp[end] = max(dp[end], dp[i] + e.second);
            ans = max(ans, dp[end]);
        }
    }

    cout << ans;
}