#include <iostream>
#include <vector>

using namespace std;

const int MN = 10001;
vector<int> g[MN];
int t[MN];
int dp[MN];

int main() {
    int N; cin >> N;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> t[i] >> a;
        while(a--) {
            int k; cin >> k;
            g[i].push_back(k);
        }
    }

    for(int i = 1; i <= N; i++) {
        int s = 0;
        for(int e : g[i]) {
            s = max(s, dp[e]);
        }
        s += t[i];
        dp[i] = s;
        ans = max(s, ans);
    }
    cout << ans;
}